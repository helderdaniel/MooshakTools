set         Date 1582798758
set         Time 2050818
set      Problem P5
set         Team a64560
set     Classify {Compile Time Error}
set         Mark 0
set         Size 1827
set Observations {}
set    Execution -1
set        State pending
set     Language {Java zipped}
set      Program src.zip
set       Report 1.html
set      Elapsed 0
set          CPU 0
set       Memory 0
set     Feedback {{Observações de &lt;b&gt;Compile Time Error&lt;/b&gt; &lt;pre&gt;src/T2timeTest.java:1: error: package org.junit does not exist
import static org.junit.Assert.*;
                       ^
src/T2timeTest.java:3: error: package org.junit does not exist
import org.junit.Test;
                ^
src/T2timeTest.java:7: error: cannot find symbol
	@Test
	 ^
  symbol:   class Test
  location: class T2timeTest
src/T2timeTest.java:15: error: cannot find symbol
	@Test (expected = IllegalArgumentException.class)
	 ^
  symbol:   class Test
  location: class T2timeTest
src/T2timeTest.java:20: error: cannot find symbol
	@Test (expected = IllegalArgumentException.class)
	 ^
  symbol:   class Test
  location: class T2timeTest
src/T2timeTest.java:25: error: cannot find symbol
	@Test
	 ^
  symbol:   class Test
  location: class T2timeTest
src/T2timeTest.java:33: error: cannot find symbol
	@Test
	 ^
  symbol:   class Test
  location: class T2timeTest
src/T2timeTest.java:9: error: cannot find symbol
		assertEquals(0, new T2time( 0).asSeconds());
		^
  symbol:   method assertEquals(int,int)
  location: class T2timeTest
src/T2timeTest.java:10: error: cannot find symbol
		assertEquals(3661, new T2time( 3661).asSeconds());
		^
  symbol:   method assertEquals(int,int)
  location: class T2timeTest
src/T2timeTest.java:12: error: cannot find symbol
		assertEquals(48435, new T2time(48435).asSeconds()); 
		^
  symbol:   method assertEquals(int,int)
  location: class T2timeTest
src/T2timeTest.java:27: error: cannot find symbol
		assertEquals("00:00:00", new T2time( 0).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTest
src/T2timeTest.java:28: error: cannot find symbol
		assertEquals("00:00:01", new T2time( 1).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTest
src/T2timeTest.java:29: error: cannot find symbol
		assertEquals("01:01:01", new T2time(3661).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTest
src/T2timeTest.java:30: error: cannot find symbol
		assertEquals("13:27:15", new T2time(T2time.T2DAYSECONDS-1).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTest
src/T2timeTest.java:35: error: cannot find symbol
		assertEquals("00:00:00", (new T2time(0,0,0).add(new T2time(0,0,0))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTest
src/T2timeTest.java:36: error: cannot find symbol
		assertEquals("00:00:01", (new T2time(0,0,1).add(new T2time(0,0,0))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTest
src/T2timeTest.java:37: error: cannot find symbol
		assertEquals("00:00:00", (new T2time(13,27,15).add(new T2time(0,0,1))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTest
src/T2timeTest.java:38: error: cannot find symbol
		assertEquals("00:00:01", (new T2time(13,27,15).add(new T2time(0,0,2))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTest
src/T2timeTest.java:39: error: cannot find symbol
		assertEquals("01:01:01", (new T2time(13,27,15).add(new T2time(1,1,2))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTest
19 errors&lt;/pre&gt;}}
