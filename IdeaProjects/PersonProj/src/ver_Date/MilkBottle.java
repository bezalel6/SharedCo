package ver_Date;

public class MilkBottle {
    private int fat;
    private double liters;
    private Date goodUntil;

    public MilkBottle(int fat, double liters, Date goodUntil) {
        this.fat = fat;
        this.liters = liters;
        this.goodUntil = goodUntil;
    }

    public int getFat() {
        return fat;
    }

    public void setFat(int fat) {
        this.fat = fat;
    }

    public double getLiters() {
        return liters;
    }

    public void setLiters(double liters) {
        this.liters = liters;
    }

    public Date getGoodUntil() {
        return goodUntil;
    }

    public void setGoodUntil(Date goodUntil) {
        this.goodUntil = goodUntil;
    }

    public int timeUntilBad()
    {
        return new Date().compareTo(goodUntil);
    }

}
