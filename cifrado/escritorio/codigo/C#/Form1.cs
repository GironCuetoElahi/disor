using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TextCipherDecipher
{
    public partial class Form1 : Form
    {
        private ICipherDecipher myCipher;

        public Form1()
        {
            myCipher = new CaeserCipher();
            //myCipher = new MyCipher();

            InitializeComponent();
        }

        private void btn_ClearUncipheredText_Click(object sender, EventArgs e)
        {
            txtb_UncipheredText.Text = string.Empty;
        }

        private void btn_ClearCipheredText_Click(object sender, EventArgs e)
        {
            txtb_CipheredText.Clear();
        }

        private void btn_Cipher_Click(object sender, EventArgs e)
        {
            string textToBeCiphered = txtb_UncipheredText.Text;

            string textCiphered = myCipher.Cipher(textToBeCiphered, 6);

            txtb_CipheredText.Text = textCiphered;
        }

        private void btn_Decipher_Click(object sender, EventArgs e)
        {
            string textToBeUnciphered = txtb_CipheredText.Text;

            string textUnciphered = myCipher.Decipher(textToBeUnciphered, 6);

            txtb_UncipheredText.Text = textUnciphered;
        }
    }
}
