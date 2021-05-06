import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

class MyImage implements Picture{
    BufferedImage img;

    public MyImage(String fileName){
        File file = new File(fileName);
        try {
            img = ImageIO.read(file);
        } catch (IOException exception) {
            exception.printStackTrace();
       }
    }

    public Image getImage(){
        return img;
    }
}

public class Proxy implements Picture{
    MyImage img;
    String file;
    public  Proxy(String file){
        this.file = file;
    }
    @Override
    public Image getImage() {
        if(img == null){
            img = new MyImage(file);
        }
        return img.getImage();
    }
}

