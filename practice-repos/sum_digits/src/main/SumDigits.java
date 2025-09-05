package main;

public class SumDigits {
    //- 输入参数解析
    //- 逻辑实现
    //- 输出打印

    //计算实现
    public static int sumDigits(String inputNum) {
        int sum = 0;

        if(inputNum == null || inputNum.isEmpty()) {
            return sum;
        }

        for(char digit : inputNum.toCharArray()) {
            if(!Character.isDigit(digit)) {
                return -1;
            }
            sum += Character.getNumericValue(digit);
        }

        return sum;
    }

    //输出实现
    public static void main(String[] args) {
//        if(args.length < 1) {
//            System.out.println("Usage: SumDigits <number>");
//            return;
//        }
//
//        int result = sumDigits(args[0]);
//        if(result == -1) {
//            System.out.println("Invalid number");
//        } else {
//            System.out.println("Sum of digits is: " + result);
//        }
        //校验和输出混在一起实现了 后续自己希望实现的操作是将校验和输出分开实现
        String input = args[0];

        // 调用工具类校验输入
        if (!InputValidator.validate(input)) {
            System.out.println("输入不合法");
            return;
        }

        int sum = sumDigits(input);

        // 打印结果
        System.out.println("数位求和:" + sum);
    }
}
