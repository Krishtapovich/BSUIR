using System.IO;
using System.Security.Cryptography;
using System.Text;

namespace LR2
{
    static class Encryptor
    {
        private static readonly DESCryptoServiceProvider crypto = new DESCryptoServiceProvider
        {
            Key = Encoding.ASCII.GetBytes("Mishanya"),
            IV = Encoding.ASCII.GetBytes("Mishanya")
        };

        public static void Encrypt(Stream sourceStream, Stream targetEncryptedStream)
        {
            using (var ecStream = new CryptoStream(targetEncryptedStream, crypto.CreateEncryptor(), CryptoStreamMode.Write))
            {
                sourceStream.CopyTo(ecStream);
            }
        }

        public static void Decrypt(Stream sourceEncryptedStream, Stream targetDecryptedStream)
        {
            using (var dcStream = new CryptoStream(sourceEncryptedStream, crypto.CreateDecryptor(), CryptoStreamMode.Read))
            {
                dcStream.CopyTo(targetDecryptedStream);
            }
        }
    }
}
