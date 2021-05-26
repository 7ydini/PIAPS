import java.util.ArrayList;

public class CurrentAcademicPerformance {
    private ArrayList<String> cap = new ArrayList<>();
    public void addCAP(String tName,String name, String mark){
        cap.add( "Преподаватель: " + tName + "\nСтудент>> "+ name + "\nОтметка>> " + mark);
    }
    public void info(){
        System.out.println("Текущая успеваемость:");
        for (String s :
                cap) {
            System.out.println(s);
        }
    }
    public boolean isEmpty(){
        return cap.isEmpty();
    }
}
