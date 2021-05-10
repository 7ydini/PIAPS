public class Marks extends AbstractExpression {
    Marks(int one){}
    @Override
    public String interpret(String context){
        context = context.replaceAll("(“)+", "«");
        context = context.replaceAll("(« \\w+ )«+", "$1»");
        context = context.replaceAll("(”)+", "»");
        return context;
    }
}
