package test;
import main.SumDigits;
import org.junit.Test;

import static junit.framework.TestCase.assertEquals;


public class TestSumDigits {
    @Test
    public void testSumDigits() {
        //正常输入测试
        int result = SumDigits.sumDigits("123");

        assertEquals(6, result);
    }
}
