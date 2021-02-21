package ver_Date;

public class TestMilkBottle {


    public static void main(String[] args) {
        MilkBottle bottle= new MilkBottle(2,2.5,new Date(25,12,2021));
        System.out.println(bottle.timeUntilBad());
    }
}
