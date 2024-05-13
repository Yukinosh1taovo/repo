
import java.util.Scanner;

interface Soundable{

    void play();
    void turnOff();
    void turnUp();
    void turnDown();

}

class Radio implements Soundable
{
    public void play()
    {
        System.out.println("Play the Radio");
    }
    public void turnOff()
    {
        System.out.println("Turn off the Radio");
    }
    public void turnUp()
    {
        System.out.println("Turn up the Radio volume");
    }
    public void turnDown()
    {
        System.out.println("Turn down the Radio volume");
    }
}

class Walkman implements Soundable
{
    public void play()
    {
        System.out.println("Play the Walkman");
    }
    public void turnOff()
    {
        System.out.println("Turn off the Walkman");
    }
    public void turnUp()
    {
        System.out.println("Turn up the Walkman volume");
    }
    public void turnDown()
    {
        System.out.println("Turn down the Walkman volume");
    }
}

class MobilePhone implements Soundable
{
    public void play()
    {
        System.out.println("Play the MobilePhone");
    }
    public void turnOff()
    {
        System.out.println("Turn off the MobilePhone");
    }
    public void turnUp()
    {
        System.out.println("Turn up the MobilePhone volume");
    }
    public void turnDown()
    {
        System.out.println("Turn down the MobilePhone volume");
    }
}

class Person
{
    String name;
    public Person(String name)
    {
        this.name = name;
    }
    void operate(String operate, Soundable device)
    {
        switch (operate)
        {
            case "A":
                System.out.printf("%s ", name);
                device.play();
                break;
            case "B":
                System.out.printf("%s ", name);
                device.turnOff();
                break;
            case "C":
                System.out.printf("%s ", name);
                device.turnUp();
                break;
            case "D":
                System.out.printf("%s ", name);
                device.turnDown();
                break;

        }
    }
}

public class Device
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String deviceName = sc.next();
        String user = sc.next();
        int n = sc.nextInt();

        Soundable device = null;
        switch (deviceName)
        {
            case "Radio":
                device = new Radio();
                break;
            case "Walkman":
                device = new Walkman();
                break;
            case "MobilePhone":
                device = new MobilePhone();
                break;


        }
        Person person = new Person(user);


        for (int i = 0; i < n; i++)
        {
            String operate = sc.next();
            person.operate(operate, device);
        }
        sc.close();
    }
}