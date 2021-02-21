package ver_Date;

public class Person {
    String name;
    int id;
    double age;
    char gender;

    public Person(String name, int id, double age, char gender) {
        this.name = name;
        this.id = id;
        this.age = age;
        this.gender = gender;
    }

    @Override
    public String toString() {
        return "ver_Date.Person{" +
                "name='" + name + '\'' +
                ", id=" + id +
                ", age=" + age +
                ", gender=" + gender +
                '}';
    }

    public String getName() {
        return name;
    }

    public int getId() {
        return id;
    }

    public double getAge() {
        return age;
    }

    public char getGender() {
        return gender;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setAge(double age) {
        this.age = age;
    }

    public void setGender(char gender) {
        this.gender = gender;
    }
}
