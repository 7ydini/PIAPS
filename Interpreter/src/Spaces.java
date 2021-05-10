public class Spaces extends AbstractExpression{
    Spaces(int one){}
    @Override
    public String interpret(String context){
        context = context.replaceAll("[ ]+", " ");
        context = context.replace(" \t", "\t");
        context = context.replace("\t ", "\t");
        context = context.replace("\t\n", "\n");
        context = context.replace("\n ", "\n");
        context = context.replace("\n\n", "\n");
        context = context.replace("( ", "(");
        context = context.replace(" )", ")");
        context = context.replace(" ,", ",");
        context = context.replace(" .", ".");
        context = context.replace(" \" ", "\" ");
        context = context.replace(" \"", "\"");
        context = context.replace("<< ", "<<");
        context = context.replace(" >>", ">>");
        context = context.replace(" ;", ";");
        return context;
    }
}
