set         Date 1583089216
set         Time 2341276
set      Problem P6
set         Team a64014
set     Classify {Compile Time Error}
set         Mark 0
set         Size 2408
set Observations {}
set    Execution -1
set        State pending
set     Language {Java zipped}
set      Program src.zip
set       Report 1.html
set      Elapsed 0
set          CPU 0
set       Memory 0
set     Feedback {{Observation of &lt;b&gt;Compile Time Error&lt;/b&gt; &lt;pre&gt;src/PiratesTest.java:1: error: package org.junit does not exist
import static org.junit.Assert.*;
                       ^
src/PiratesTest.java:2: error: package org.junit does not exist
import org.junit.Test;
                ^
src/PiratesTest.java:9: error: cannot find symbol
    @Test
     ^
  symbol:   class Test
  location: class PiratesTest
src/PiratesTest.java:23: error: cannot find symbol
    @Test (expected = IllegalArgumentException.class)
     ^
  symbol:   class Test
  location: class PiratesTest
src/PiratesTest.java:28: error: cannot find symbol
    @Test (expected = IllegalArgumentException.class)
     ^
  symbol:   class Test
  location: class PiratesTest
src/PiratesTest.java:33: error: cannot find symbol
    @Test (expected = IllegalArgumentException.class)
     ^
  symbol:   class Test
  location: class PiratesTest
src/PiratesTest.java:38: error: cannot find symbol
    @Test (expected = IllegalArgumentException.class)
     ^
  symbol:   class Test
  location: class PiratesTest
src/PiratesTest.java:43: error: cannot find symbol
    @Test
     ^
  symbol:   class Test
  location: class PiratesTest
src/PiratesTest.java:50: error: cannot find symbol
    @Test
     ^
  symbol:   class Test
  location: class PiratesTest
src/PiratesTest.java:68: error: cannot find symbol
    @Test
     ^
  symbol:   class Test
  location: class PiratesTest
src/PiratesTest.java:75: error: cannot find symbol
    @Test
     ^
  symbol:   class Test
  location: class PiratesTest
src/PiratesTest.java:83: error: cannot find symbol
    @Test
     ^
  symbol:   class Test
  location: class PiratesTest
src/PiratesTest.java:14: error: cannot find symbol
        assertEquals(Arrays.toString(out1), new Pirates(in1).toString());
        ^
  symbol:   method assertEquals(String,String)
  location: class PiratesTest
src/PiratesTest.java:17: error: cannot find symbol
        assertEquals(Arrays.toString(out2), new Pirates(in2).toString());
        ^
  symbol:   method assertEquals(String,String)
  location: class PiratesTest
src/PiratesTest.java:20: error: cannot find symbol
        assertEquals(Arrays.toString(out3), new Pirates(in3).toString());
        ^
  symbol:   method assertEquals(String,String)
  location: class PiratesTest
src/PiratesTest.java:45: error: cannot find symbol
        assertEquals(5, new Pirates("11111").sumOfDigits(11111));
        ^
  symbol:   method assertEquals(int,int)
  location: class PiratesTest
src/PiratesTest.java:46: error: cannot find symbol
        assertEquals(10, new Pirates("3151").sumOfDigits(3151));
        ^
  symbol:   method assertEquals(int,int)
  location: class PiratesTest
src/PiratesTest.java:47: error: cannot find symbol
        assertEquals(23, new Pirates("13289").sumOfDigits(13289));
        ^
  symbol:   method assertEquals(int,int)
  location: class PiratesTest
src/PiratesTest.java:55: error: cannot find symbol
        assertEquals(Arrays.toString(out1), Arrays.toString(in1));
        ^
  symbol:   method assertEquals(String,String)
  location: class PiratesTest
src/PiratesTest.java:60: error: cannot find symbol
        assertEquals(Arrays.toString(out2), Arrays.toString(in2));
        ^
  symbol:   method assertEquals(String,String)
  location: class PiratesTest
src/PiratesTest.java:65: error: cannot find symbol
        assertEquals(Arrays.toString(out3), Arrays.toString(in3));
        ^
  symbol:   method assertEquals(String,String)
  location: class PiratesTest
src/PiratesTest.java:70: error: cannot find symbol
        assertEquals("[-1, 1, 1]", new Pirates("12").toString());
        ^
  symbol:   method assertEquals(String,String)
  location: class PiratesTest
src/PiratesTest.java:71: error: cannot find symbol
        assertEquals("[-1, -1, 1]", new Pirates("21").toString());
        ^
  symbol:   method assertEquals(String,String)
  location: class PiratesTest
src/PiratesTest.java:72: error: cannot find symbol
        assertEquals("[-1, 1, -1, -1, -1]", new Pirates("113").toString());
        ^
  symbol:   method assertEquals(String,String)
  location: class PiratesTest
src/PiratesTest.java:77: error: cannot find symbol
        assertEquals(3, new Pirates("3151").smallestStep());
        ^
  symbol:   method assertEquals(int,int)
  location: class PiratesTest
src/PiratesTest.java:78: error: cannot find symbol
        assertEquals(12, new Pirates("14115123").smallestStep());
        ^
  symbol:   method assertEquals(int,int)
  location: class PiratesTest
src/PiratesTest.java:79: error: cannot find symbol
        assertEquals(1, new Pirates("11").smallestStep());
        ^
  symbol:   method assertEquals(int,int)
  location: class PiratesTest
src/PiratesTest.java:80: error: cannot find symbol
        assertNotEquals(1, new Pirates("111").smallestStep());
        ^
  symbol:   method assertNotEquals(int,int)
  location: class PiratesTest
src/PiratesTest.java:91: error: cannot find symbol
        assertEquals(list1, new Pirates("123").createList(arr1));
        ^
  symbol:   method assertEquals(List&lt;Integer&gt;,List&lt;Integer&gt;)
  location: class PiratesTest
src/PiratesTest.java:98: error: cannot find symbol
        assertEquals(list2, new Pirates("31").createList(arr2));
        ^
  symbol:   method assertEquals(List&lt;Integer&gt;,List&lt;Integer&gt;)
  location: class PiratesTest
src/PiratesTest.java:101: error: cannot find symbol
        assertNotEquals(list1, new Pirates("321").createList(arr3));
        ^
  symbol:   method assertNotEquals(List&lt;Integer&gt;,List&lt;Integer&gt;)
  location: class PiratesTest
31 errors&lt;/pre&gt;}}
