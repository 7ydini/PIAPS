import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.image.ImageObserver;
import javax.swing.*;
import javax.swing.event.MouseInputAdapter;

public class Form extends JFrame {
    JFrame frame = new JFrame("Proxy");
    JPanel panel = new JPanel();
    JLabel label;

    private final int width = 1920;
    private final int height = 1080;

    public Form() {
        frame.setSize(width, height);
        frame.setTitle("Picture");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(null);
        frame.setLocationRelativeTo(null);
        frame.setResizable(false);
        frame.setVisible(true);
        Image image = new Proxy("src/image.jpg").getImage();
        ImageObserver io = (img, infoflags, x, y, width, height) -> false;
        int imageH = image.getHeight(io);
        int imageW = image.getWidth(io);
        label = new JLabel();
        //panel.setBounds(100, 100, imageW, imageH);
        panel.setSize(imageW, imageH);
        panel.setBackground(Color.GRAY);
        DragListener drag = new DragListener();
        MouseAdapter ma = new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                if(e.getButton() == MouseEvent.BUTTON3 && e.getClickCount() == 2 && !e.isConsumed()){
                    e.consume();
                    label.setIcon(new ImageIcon(image));
                    panel.repaint();
                }
            }
        };
        frame.addMouseListener(ma);
        panel.addMouseListener(ma);
        panel.addMouseListener( drag );
        panel.addMouseMotionListener( drag );
        panel.add(label);
        frame.add(panel);
        frame.repaint();
    }
    public static class DragListener extends MouseInputAdapter
    {
        Point location;
        MouseEvent pressed;

        public void mousePressed(MouseEvent me)
        {
            pressed = me;
        }

        public void mouseDragged(MouseEvent me)
        {
            Component component = me.getComponent();
            location = component.getLocation(location);
            int x = location.x - pressed.getX() + me.getX();
            int y = location.y - pressed.getY() + me.getY();
            component.setLocation(x, y);
        }
    }
}