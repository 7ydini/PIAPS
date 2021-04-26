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
        Image getImage();
    }


    class Proxy : Picture
    {
        String file;
        MyImage img;
        public Proxy(String file)
        {
            this.file = file;
        }
        public Image getImage()
        {
            if (img == null)
            {
                img = new MyImage(file);
            }
            return img.getImage();
        }
    }


    class MyImage : Picture
    {
        Image img;
        public MyImage(String fileName)
        {
            img = Image.FromFile(fileName);
        }
        public Image getImage()
        {
            return img;
        }
    }
}
