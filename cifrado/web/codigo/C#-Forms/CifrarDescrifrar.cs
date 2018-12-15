using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TextCipherDecipher
{
    interface ICipherDecipher
    {
        string Cipher(params object[] arguments);
        string Decipher(params object[] arguments);
    }
}
