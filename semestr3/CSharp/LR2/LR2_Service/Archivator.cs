using System;
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
                        FileStream sourceStream = default;

                        while (true)//Catching file locked in other process
                        {           //Until it free from other process
                            try
                            {
                                sourceStream = new FileStream(fileName, FileMode.Open);
                            }
                            catch (IOException)
                            {
                                continue;
                            }
                            break;
                        }

                        using (Stream targetEncryptedStream = memoryFile.Open())
                        {
                            Encryptor.Encrypt(sourceStream, targetEncryptedStream);
                        }
                        sourceStream.Close();
                        sourceStream.Dispose();
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
                    using (Stream targetDecryptedStream = file.Open())
                        Encryptor.Decrypt(targetDecryptedStream, targetStream);
                }
            }
            catch (Exception e)
            {
                using (var errorStream = new StreamWriter(new FileStream(errorFile, FileMode.OpenOrCreate)))
                {
                    errorStream.Write(e.Message + "\n\n" + e.StackTrace);
                }
            }
            Thread.Sleep(100);
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