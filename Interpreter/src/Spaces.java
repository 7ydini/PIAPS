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
        String[] arr = context.split(".");
        for(String array: arr){
        	if(array.length() > 0){
        	array.replaceFirst(String.valueOf(array.charAt(1)), String.valueOf(array.charAt(1)).toUpperCase());
        	//array.charAt(1);
        	//array.substring(1).toUpperCase();
        	}
        	System.out.println(array);
        	//array.replace(array.charAt(1),String.valueOf(array.charAt(1)).toUpperCase().);// String.valueOf(array.charAt(1)).toUpperCase();
        }
        String mess = "";
        for(String array: arr){
        	mess += array + ".";
        }
        return mess;
        */
    }
}
