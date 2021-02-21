package ver_Date;

import java.util.Scanner;

public class TestDate {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        Date date = new Date(25,2,2004);
        System.out.println("Enter Days");
        int days = s.nextInt();

        Date res = date.getTomorrow();
        for (int i = 1; i < days; i++) {
            res = res.getTomorrow();
            System.out.println(res);
        }
    }
}
