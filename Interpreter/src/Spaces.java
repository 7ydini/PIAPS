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
        /*
        String mess = "";
        for(String array: arr){
        	if(array.length() > 1){
        		if(arr[0] == array){
        			mess += array.replaceFirst(String.valueOf(array.charAt(0)), String.valueOf(array.charAt(0)).toUpperCase()) + ".";
        		}else{
        			mess += array.replaceFirst(String.valueOf(array.charAt(1)), String.valueOf(array.charAt(1)).toUpperCase()) + ".";
        		}
        	}
        }
        return mess;
        */
    }
}
