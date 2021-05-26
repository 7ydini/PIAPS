public class Teacher implements Observer {
    private String name;
    private CurrentAcademicPerformance cap;
    Observable stock;
    public Teacher(String name, Observable observer){
        this.name = name;
        stock = observer;
        stock.RegisterObserver(this);
    }

    @Override
    public void Update(Object o) {
        cap = new CurrentAcademicPerformance();

    }

    public String getName() {
        return name;
    }
}
