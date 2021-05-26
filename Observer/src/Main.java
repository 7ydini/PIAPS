import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Stock stock = new Stock();
        Teacher teacher;
        StockInfo SI = new StockInfo();
        int mode = 0;
        CurrentAcademicPerformance CAP = new CurrentAcademicPerformance();
        Scanner scanner = new Scanner(System.in);
        while(mode != 3) {
            System.out.println("1)Войти как учитель\n2)Информация о текущей успеваемости\n3)Выход");
            mode = scanner.nextInt();
            scanner.nextLine();
            switch (mode){
                case (1):{
                    System.out.println("Введите имя>>");
                    teacher = new Teacher(scanner.nextLine(), stock);
                    int mode1 = 0;
                    while (mode1 != 2){
                        System.out.println("1)Добавить отметку в успеваемость.\n2)Добавить успеваемость.");
                        mode1 = scanner.nextInt();
                        scanner.nextLine();
                        switch (mode1){
                            case 1:{
                                SI.setTeacherName(teacher.getName());
                                System.out.print("Введите имя студента>>");
                                SI.setName(scanner.nextLine());
                                System.out.print("Введите отмеку студента>>");
                                SI.setMark(scanner.nextLine());

                                CAP.addCAP(SI.getTeacherName(), SI.getName(), SI.getMark());
                                System.out.println("Отметка добавлена!");
                                break;
                            }
                            case 2:{
                                CAP.info();
                                if (CAP.isEmpty()){
                                    stock.sendInfo();
                                }
                                break;
                            }
                        }
                    }
                    break;
                }
                case 2, 3:{
                    CAP.info();
                    break;
                }
            }
        }
    }
}
