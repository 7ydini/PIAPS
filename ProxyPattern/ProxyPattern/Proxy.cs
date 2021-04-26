using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace ProxyPattern
{
    interface Picture
    {
        Image GetImage();
    }
    class Proxy : Picture
    {
        String file;
        MyImage img;
        public Proxy(String file)
        {
            this.file = file;
        }
        public Image GetImage()
        {
            if (img == null)
            {
                img = new MyImage(file);
            }
            return img.GetImage();
        }
    }
    class MyImage : Picture
    {
        Image img;
        public MyImage(String fileName)
        {
            img = Image.FromFile(fileName);
        }
        public Image GetImage()
        {
            return img;
        }
    }
}
