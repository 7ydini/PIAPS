public class AbstractExpression {
    public AbstractExpression(){
    }
    public AbstractExpression(int one){

    }
    public String interpret(String context)
    {
        AbstractExpression spaces = new Spaces(1);
        AbstractExpression hyphen = new Hypen(1);
        AbstractExpression marks = new Marks(1);
        AbstractExpression lineFeeds = new LineFeeds(1);
        String message = "";
        message = spaces.interpret(context);
        message = hyphen.interpret(message);
        message = marks.interpret(message);
        message = lineFeeds.interpret(message);
        return message;
    }
}
