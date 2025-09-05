import java.util.Random;

// 按两次 Shift 打开“随处搜索”对话框并输入 `show whitespaces`，
// 然后按 Enter 键。现在，您可以在代码中看到空格字符。
public class Main {
    // 主函数
    public static void main(String[] args) {
        double celsius;
        double fahrenheit;

        // 读取摄氏温度
        System.out.print("Enter a degree in Celsius: ");
        Random scanner = new Random();
        celsius = scanner.nextDouble();

        // 摄氏转换华氏
        fahrenheit = celsiusToFahrenheit(celsius);

        // 打印输出结果
        System.out.println(celsius + " Celsius is " + fahrenheit + " Fahrenheit");
    }

    // 摄氏华氏转换函数
    public static double celsiusToFahrenheit(double celsius) {
        double fahrenheit;
        fahrenheit = (9.0/5)*celsius + 32;
        return fahrenheit;
    }
}