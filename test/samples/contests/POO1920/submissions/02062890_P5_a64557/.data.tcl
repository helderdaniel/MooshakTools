set         Date 1582810830
set         Time 2062890
set      Problem P5
set         Team a64557
set     Classify {Compile Time Error}
set         Mark 0
set         Size 2157
set Observations {}
set    Execution -1
set        State pending
set     Language {Java zipped}
set      Program src.zip
set       Report 1.html
set      Elapsed 0
set          CPU 0
set       Memory 0
set     Feedback {{Observações de &lt;b&gt;Compile Time Error&lt;/b&gt; &lt;pre&gt;src/Time2Test.java:1: error: package org.junit does not exist
import static org.junit.Assert.*;
                       ^
src/Time2Test.java:2: error: package org.junit does not exist
import org.junit.Test;
                ^
src/Time2Test.java:6: error: cannot find symbol
    @Test
     ^
  symbol:   class Test
  location: class Time2Test
src/Time2Test.java:13: error: cannot find symbol
    @Test (expected = IllegalArgumentException.class)
     ^
  symbol:   class Test
  location: class Time2Test
src/Time2Test.java:18: error: cannot find symbol
    @Test (expected = IllegalArgumentException.class)
     ^
  symbol:   class Test
  location: class Time2Test
src/Time2Test.java:23: error: cannot find symbol
    @Test
     ^
  symbol:   class Test
  location: class Time2Test
src/Time2Test.java:31: error: cannot find symbol
    @Test
     ^
  symbol:   class Test
  location: class Time2Test
src/Time2Test.java:8: error: cannot find symbol
        assertEquals(0, new Time2( 0).asSeconds());
        ^
  symbol:   method assertEquals(int,int)
  location: class Time2Test
src/Time2Test.java:9: error: cannot find symbol
        assertEquals(3661, new Time2( 3661).asSeconds());
        ^
  symbol:   method assertEquals(int,int)
  location: class Time2Test
src/Time2Test.java:10: error: cannot find symbol
        assertEquals(48435, new Time2(48435).asSeconds());
        ^
  symbol:   method assertEquals(int,int)
  location: class Time2Test
src/Time2Test.java:25: error: cannot find symbol
        assertEquals("00:00:00", new Time2( 0).toString());
        ^
  symbol:   method assertEquals(String,String)
  location: class Time2Test
src/Time2Test.java:26: error: cannot find symbol
        assertEquals("00:00:01", new Time2( 1).toString());
        ^
  symbol:   method assertEquals(String,String)
  location: class Time2Test
src/Time2Test.java:27: error: cannot find symbol
        assertEquals("01:01:01", new Time2(3661).toString());
        ^
  symbol:   method assertEquals(String,String)
  location: class Time2Test
src/Time2Test.java:28: error: cannot find symbol
        assertEquals("13:27:15", new Time2(Time2.T2DAYSECONDS-1).toString());
        ^
  symbol:   method assertEquals(String,String)
  location: class Time2Test
src/Time2Test.java:33: error: cannot find symbol
        assertEquals("00:00:00",
        ^
  symbol:   method assertEquals(String,String)
  location: class Time2Test
src/Time2Test.java:35: error: cannot find symbol
        assertEquals("00:00:01",
        ^
  symbol:   method assertEquals(String,String)
  location: class Time2Test
src/Time2Test.java:37: error: cannot find symbol
        assertEquals("00:00:00",
        ^
  symbol:   method assertEquals(String,String)
  location: class Time2Test
src/Time2Test.java:39: error: cannot find symbol
        assertEquals("00:00:01",
        ^
  symbol:   method assertEquals(String,String)
  location: class Time2Test
src/Time2Test.java:41: error: cannot find symbol
        assertEquals("01:01:01",
        ^
  symbol:   method assertEquals(String,String)
  location: class Time2Test
19 errors&lt;/pre&gt;}}
