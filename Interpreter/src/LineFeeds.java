public class LineFeeds extends AbstractExpression{
    LineFeeds(int one){}
    @Override
    public String interpret(String context) {
        context = context.replace("\r\n ", "\r\n");
        return context;
    }
}
