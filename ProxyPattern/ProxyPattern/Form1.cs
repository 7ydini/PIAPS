using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ProxyPattern
{
    public partial class Form1 : Form
    {
        private PictureForm picture;
        public Form1()
        {
            InitializeComponent();
            this.MouseDown += DragListener;
        }
        public void DragListener(Object Sender, MouseEventArgs args)
        {
            if (picture == null)
            {
                picture = new PictureForm(new Proxy("../../TestImage.jpg"), args.X, args.Y, 200, 200);
                this.Controls.Add(picture);
            }
        }
    }
}
