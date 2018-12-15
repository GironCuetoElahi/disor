using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TextCipherDecipher
{
    class CaeserCipher : ICipherDecipher
    {
        public string Cipher(params object[] arguments)
        {
            if ( arguments.Length == 2 )
            {
                string text = arguments[0] as string;
                int shift = (int)arguments[1];

                return Cipher(text, shift);
            }

            return string.Empty;
        }

        public string Decipher(params object[] arguments)
        {
            if (arguments.Length == 2)
            {
                string text = arguments[0] as string;
                int shift = (int)arguments[1];

                return Decipher(text, shift);
            }

            return string.Empty;
        }

        private string Cipher( string text, int shift )
        {
            StringBuilder result = new StringBuilder();

            string alphabet = "0123456789abcdefghijklmnopqrstuvxywzABCDEFGHIJKLMNOPQRSTUWVXYZ !";
            int offset = alphabet.Length;

            foreach( char c in text )
            {
                char oldChar = c;
                int oldCharIdx = alphabet.IndexOf(c);

                int newCharIdx = (oldCharIdx + shift + offset) % offset;

                char newChar = alphabet[newCharIdx];

                result.Append(newChar);
            }

            return result.ToString();
        }

        private string Decipher( string text, int shift )
        {
            return Cipher(text, shift * -1);
        }
    }
}
