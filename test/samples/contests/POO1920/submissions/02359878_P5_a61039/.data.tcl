set         Date 1583107818
set         Time 2359878
set      Problem P5
set         Team a61039
set     Classify {Compile Time Error}
set         Mark 0
set         Size 2731
set Observations {}
set    Execution -1
set        State pending
set     Language {Java zipped}
set      Program T2time.zip
set       Report 1.html
set      Elapsed 0
set          CPU 0
set       Memory 0
set     Feedback {{Observações de &lt;b&gt;Compile Time Error&lt;/b&gt; &lt;pre&gt;T2time/ClientTest.java:3: error: package org.junit does not exist
import static org.junit.Assert.*;
                       ^
T2time/ClientTest.java:4: error: package org.junit does not exist
import org.junit.Test;
                ^
T2time/T2timeTests.java:3: error: package org.junit does not exist
import static org.junit.Assert.*;
                       ^
T2time/T2timeTests.java:4: error: package org.junit does not exist
import org.junit.Test;
                ^
T2time/ClientTest.java:33: error: cannot find symbol
	@Test
	 ^
  symbol:   class Test
  location: class ClientTest
T2time/T2timeTests.java:7: error: cannot find symbol
	@Test
	 ^
  symbol:   class Test
  location: class T2timeTests
T2time/T2timeTests.java:15: error: cannot find symbol
	@Test(expected = IllegalArgumentException.class)
	 ^
  symbol:   class Test
  location: class T2timeTests
T2time/T2timeTests.java:20: error: cannot find symbol
	@Test(expected = IllegalArgumentException.class)
	 ^
  symbol:   class Test
  location: class T2timeTests
T2time/T2timeTests.java:25: error: cannot find symbol
	@Test
	 ^
  symbol:   class Test
  location: class T2timeTests
T2time/T2timeTests.java:33: error: cannot find symbol
	@Test
	 ^
  symbol:   class Test
  location: class T2timeTests
T2time/ClientTest.java:40: error: cannot find symbol
			assertEquals(expected, os.toString());
			^
  symbol:   method assertEquals(String,String)
  location: class ClientTest
T2time/T2timeTests.java:9: error: cannot find symbol
		assertEquals(0, new T2time(0).asSeconds());
		^
  symbol:   method assertEquals(int,int)
  location: class T2timeTests
T2time/T2timeTests.java:10: error: cannot find symbol
		assertEquals(3661, new T2time(3661).asSeconds());
		^
  symbol:   method assertEquals(int,int)
  location: class T2timeTests
T2time/T2timeTests.java:12: error: cannot find symbol
		assertEquals(48435, new T2time(48435).asSeconds());
		^
  symbol:   method assertEquals(int,int)
  location: class T2timeTests
T2time/T2timeTests.java:27: error: cannot find symbol
		assertEquals("00:00:00", new T2time(0).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
T2time/T2timeTests.java:28: error: cannot find symbol
		assertEquals("00:00:01", new T2time(1).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
T2time/T2timeTests.java:29: error: cannot find symbol
		assertEquals("01:01:01", new T2time(3661).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
T2time/T2timeTests.java:30: error: cannot find symbol
		assertEquals("13:27:15", new T2time(T2time.T2DAYSECONDS - 1).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
T2time/T2timeTests.java:35: error: cannot find symbol
		assertEquals("00:00:00", (new T2time(0, 0, 0).add(new T2time(0, 0, 0))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
T2time/T2timeTests.java:36: error: cannot find symbol
		assertEquals("00:00:01", (new T2time(0, 0, 1).add(new T2time(0, 0, 0))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
T2time/T2timeTests.java:37: error: cannot find symbol
		assertEquals("00:00:00", (new T2time(13, 27, 15).add(new T2time(0, 0, 1))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
T2time/T2timeTests.java:38: error: cannot find symbol
		assertEquals("00:00:01", (new T2time(13, 27, 15).add(new T2time(0, 0, 2))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
T2time/T2timeTests.java:39: error: cannot find symbol
		assertEquals("01:01:01", (new T2time(13, 27, 15).add(new T2time(1, 1, 2))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
23 errors&lt;/pre&gt;}}
