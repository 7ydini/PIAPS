import java.util.ArrayList;

public class Stock implements Observable{
    ArrayList<Observer> observers;
    StockInfo sInfo;
    public Stock(){
        observers = new ArrayList<Observer>();
        sInfo = new StockInfo();
    }
    @Override
    public void RegisterObserver(Observer o) {
        observers.add(o);
    }

    @Override
    public void RemoveObserver(Observer o) {
        observers.remove(o);
    }

    @Override
    public void NotifyObservers() {
        for (Observer o :
                observers) {
            o.Update(sInfo);
        }
    }

    public void sendInfo(){
        NotifyObservers();
    }
}
