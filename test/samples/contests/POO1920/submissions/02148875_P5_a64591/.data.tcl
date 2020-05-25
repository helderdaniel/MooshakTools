set         Date 1582896815
set         Time 2148875
set      Problem P5
set         Team a64591
set     Classify {Compile Time Error}
set         Mark 0
set         Size 3073
set Observations {}
set    Execution -1
set        State pending
set     Language {Java zipped}
set      Program src.zip
set       Report 1.html
set      Elapsed 0
set          CPU 0
set       Memory 0
set     Feedback {{Observações de &lt;b&gt;Compile Time Error&lt;/b&gt; &lt;pre&gt;src/ClientTest.java:3: error: package org.junit does not exist
import static org.junit.Assert.*;
                       ^
src/ClientTest.java:4: error: package org.junit does not exist
import org.junit.Test;
                ^
src/T2timeTests.java:3: error: package org.junit does not exist
import static org.junit.Assert.*;
                       ^
src/T2timeTests.java:5: error: package org.junit does not exist
import org.junit.Test;
                ^
src/ClientTest.java:33: error: cannot find symbol
	@Test
	 ^
  symbol:   class Test
  location: class ClientTest
src/T2timeTests.java:9: error: cannot find symbol
	@Test
	 ^
  symbol:   class Test
  location: class T2timeTests
src/T2timeTests.java:21: error: cannot find symbol
	@Test(expected = IllegalArgumentException.class)
	 ^
  symbol:   class Test
  location: class T2timeTests
src/T2timeTests.java:26: error: cannot find symbol
	@Test(expected = IllegalArgumentException.class)
	 ^
  symbol:   class Test
  location: class T2timeTests
src/T2timeTests.java:31: error: cannot find symbol
	@Test
	 ^
  symbol:   class Test
  location: class T2timeTests
src/T2timeTests.java:39: error: cannot find symbol
	@Test
	 ^
  symbol:   class Test
  location: class T2timeTests
src/ClientTest.java:40: error: cannot find symbol
			assertEquals(expected, os.toString());
			^
  symbol:   method assertEquals(String,String)
  location: class ClientTest
src/T2timeTests.java:11: error: cannot find symbol
		assertEquals(0, new T2Time(0).asSeconds());
		^
  symbol:   method assertEquals(int,int)
  location: class T2timeTests
src/T2timeTests.java:12: error: cannot find symbol
		assertEquals(3661, new T2Time(3661).asSeconds());
		^
  symbol:   method assertEquals(int,int)
  location: class T2timeTests
src/T2timeTests.java:13: error: cannot find symbol
		assertEquals(48435, new T2Time(48435).asSeconds());
		^
  symbol:   method assertEquals(int,int)
  location: class T2timeTests
src/T2timeTests.java:33: error: cannot find symbol
		assertEquals("00:00:00", new T2Time(0).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
src/T2timeTests.java:34: error: cannot find symbol
		assertEquals("00:00:01", new T2Time(1).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
src/T2timeTests.java:35: error: cannot find symbol
		assertEquals("01:01:01", new T2Time(3661).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
src/T2timeTests.java:36: error: cannot find symbol
		assertEquals("13:27:15", new T2Time(T2Time.T2DAYSECONDS - 1).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
src/T2timeTests.java:41: error: cannot find symbol
		assertEquals("00:00:00", (new T2Time(0, 0, 0).add(new T2Time(0, 0, 0))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
src/T2timeTests.java:42: error: cannot find symbol
		assertEquals("00:00:01", (new T2Time(0, 0, 1).add(new T2Time(0, 0, 0))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
src/T2timeTests.java:43: error: cannot find symbol
		assertEquals("00:00:00", (new T2Time(13, 27, 15).add(new T2Time(0, 0, 1))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
src/T2timeTests.java:44: error: cannot find symbol
		assertEquals("00:00:01", (new T2Time(13, 27, 15).add(new T2Time(0, 0, 2))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
src/T2timeTests.java:45: error: cannot find symbol
		assertEquals("01:01:01", (new T2Time(13, 27, 15).add(new T2Time(1, 1, 2))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
23 errors&lt;/pre&gt;}}
