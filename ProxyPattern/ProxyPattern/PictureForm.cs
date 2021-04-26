using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Windows.Forms;

namespace ProxyPattern
{
    class PictureForm : PictureBox
    {
        int lastX;
        int lastY;
        Picture imageContainer;
        public PictureForm(Picture imageContainer, int x, int y, int w, int h)
        {
            this.imageContainer = imageContainer;
            this.Height = h;
            this.Width = w;
            this.Top = y;
            this.Left = x;
            this.MouseMove += DragLisener;
            this.MouseDoubleClick += MouseRClick;
            BackColor = Color.White;
            SizeMode = PictureBoxSizeMode.AutoSize;
        }
        public void LoadPicture()
        {
            Image = imageContainer.GetImage();
        }
        public void DragLisener(Object Sender, MouseEventArgs args)
        {
            int dx = args.X - lastX;
            int dy = args.Y - lastY;
            lastX = args.X;
            lastY = args.Y;
            if (args.Button == MouseButtons.Left)
            {
                Top += dy;
                Left += dx;
                lastY -= dy;
                lastX -= dx;
            }
        }
        public void MouseRClick(object Sender, MouseEventArgs args)
        {
            if (args.Button == MouseButtons.Right)
            {
                LoadPicture();
            }
        }
    }
}
