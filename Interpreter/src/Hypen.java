public class Hypen extends AbstractExpression {
    Hypen(int one){}
    @Override
    public String interpret(String context){
        context = context.replace(" - ", " — ");
        return context;
    }

}
