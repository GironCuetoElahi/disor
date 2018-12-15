using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TextCipherDecipher
{
    class MyCipher : ICipherDecipher
    {
        private List<Code> alphabet;

        public MyCipher()
        {
            alphabet = new List<Code>();

            alphabet.Add(new Code("A", "1234"));
            alphabet.Add(new Code("B", "1244"));
            alphabet.Add(new Code("C", "1254"));
            alphabet.Add(new Code("D", "1634"));
            alphabet.Add(new Code("E", "1734"));
            alphabet.Add(new Code("F", "8234"));
            alphabet.Add(new Code("G", "3234"));
            alphabet.Add(new Code("H", "4234"));
            alphabet.Add(new Code("I", "6234"));
            alphabet.Add(new Code("J", "2234"));
            alphabet.Add(new Code("K", "0110"));
            alphabet.Add(new Code("L", "0120"));
            alphabet.Add(new Code("M", "0130"));
            alphabet.Add(new Code("N", "0140"));
            alphabet.Add(new Code("O", "0150"));
            alphabet.Add(new Code("P", "0160"));
            alphabet.Add(new Code("Q", "0170"));
            alphabet.Add(new Code("R", "0180"));
            alphabet.Add(new Code("S", "0190"));
            alphabet.Add(new Code("T", "0210"));
            alphabet.Add(new Code("U", "0220"));
            alphabet.Add(new Code("V", "0230"));
            alphabet.Add(new Code("W", "0240"));
            alphabet.Add(new Code("X", "0250"));
            alphabet.Add(new Code("Y", "0260"));
            alphabet.Add(new Code("Z", "0270"));
        }

        public string Cipher(params object[] arguments)
        {
            if ( arguments.Length > 0 )
            {
                string text = arguments[0] as string;
                return Cipher(text);
            }

            return string.Empty;
        }

        public string Decipher(params object[] arguments)
        {
            if (arguments.Length > 0)
            {
                string text = arguments[0] as string;
                return Decipher(text);
            }

            return string.Empty;
        }

        private string Cipher( string text )
        {
            StringBuilder result = new StringBuilder();

            foreach( char code in text )
            {
                Code element =
                    alphabet.Where(x => x.MyCode == code.ToString())
                    .SingleOrDefault();

                if ( element != null )
                {
                    result.Append(element.MyDecode);
                }
            }

            return result.ToString();
        }

        private string Decipher( string text )
        {
            StringBuilder result = new StringBuilder();

            string[] chars = SplitIntChunks(text, 4);

            foreach ( string c in chars )
            {
                Code element =
                    alphabet.Where(x => x.MyDecode == c).SingleOrDefault();

                if ( element != null )
                {
                    result.Append(element.MyCode);
                }
            }

            return result.ToString();
        }

        private string[] SplitIntChunks(string text, int chunkSize)
        {
            List<string> result = new List<string>();

            string chunk = string.Empty;

            foreach( char c in text)
            {
                chunk += c;
                if ( chunk.Length == chunkSize )
                {
                    result.Add(chunk);

                    chunk = string.Empty;
                }
            }

            return result.ToArray();
        }

        class Code
        {
            public string MyCode;
            public string MyDecode;

            public Code( string code, string decode )
            {
                MyCode = code;
                MyDecode = decode;
            }
        }
    }
}
