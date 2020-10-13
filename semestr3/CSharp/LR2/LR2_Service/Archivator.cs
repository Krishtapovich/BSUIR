using System;
using System.CodeDom;
using System.Diagnostics;
using System.IO;
using System.IO.Compression;
using System.Security.Cryptography;
using System.Text;
using System.Threading;

namespace LR2
{
    static class Archivator
    {
        private static string encryptedFileName;

        private static string decryptedFileName;

        public static readonly string errorFile = @"E:\LR2_Service\Error.txt";

        private static readonly DESCryptoServiceProvider crypto = new DESCryptoServiceProvider
        {
            Key = Encoding.ASCII.GetBytes("Mishanya"),
            IV = Encoding.ASCII.GetBytes("Mishanya")
        };

        public static void Archive(string fileName, string targetDir)
        {
            encryptedFileName = TargetEncryptedFilePath(fileName, targetDir);
            try
            {
                using (var memory = new MemoryStream())
                {
                    using (var zip = new ZipArchive(memory, ZipArchiveMode.Create, true))
                    {
                        var memoryFile = zip.CreateEntry(Path.GetFileName(encryptedFileName));
                        using (var ecStream = new CryptoStream(memoryFile.Open(), crypto.CreateEncryptor(), CryptoStreamMode.Write))
                        using (var sourceStream = new FileStream(fileName, FileMode.Open, FileAccess.Read, FileShare.None))
                            sourceStream.CopyTo(ecStream);
                    }
                    using (var encryptedFileStream = new FileStream(Path.Combine(targetDir, Path.GetFileNameWithoutExtension(fileName) + ".zip"), FileMode.Create))
                    {
                        memory.Seek(0, SeekOrigin.Begin);
                        memory.CopyTo(encryptedFileStream);
                    }
                }
            }
            catch (Exception e)
            {
                using (var errorStream = new StreamWriter(new FileStream(errorFile, FileMode.OpenOrCreate)))
                {
                    errorStream.Write(e.Message + "\n\n" + e.StackTrace);
                }
            }
        }

        public static void Dearchive(string fileName, string targetDir)
        {
            try
            {
                using (var zip = ZipFile.OpenRead(fileName))
                {
                    var file = zip.Entries[0];
                    decryptedFileName = TargetDecryptedFilePath(file.Name, targetDir);
                    using (var targetStream = new FileStream(decryptedFileName, FileMode.OpenOrCreate, FileAccess.Write))
                    using (var dcStream = new CryptoStream(file.Open(), crypto.CreateDecryptor(), CryptoStreamMode.Read))
                        dcStream.CopyTo(targetStream);
                }
            }
            catch (Exception e)
            {
                using (var errorStream = new StreamWriter(new FileStream(errorFile, FileMode.OpenOrCreate)))
                {
                    errorStream.Write(e.Message + "\n\n" + e.StackTrace);
                }
            }
        }

        private static string TargetEncryptedFilePath(string fileName, string targetDir)
        {
            fileName = fileName.Replace(Path.GetDirectoryName(fileName), targetDir);
            return fileName.Replace(Path.GetFileName(fileName), Path.GetFileNameWithoutExtension(fileName) + "_encrypted" + Path.GetExtension(fileName));
        }

        private static string TargetDecryptedFilePath(string fileName, string targetDir)
        {
            fileName = Path.Combine(targetDir, fileName);
            string name = Path.GetFileNameWithoutExtension(fileName);
            name = name.Replace("_encrypted", "_decrypted");
            return fileName.Replace(Path.GetFileNameWithoutExtension(fileName), name);
        }
    }
}
