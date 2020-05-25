set         Date 1582819596
set         Time 2071656
set      Problem P5
set         Team a62905
set     Classify {Compile Time Error}
set         Mark 0
set         Size 2250
set Observations {}
set    Execution -1
set        State pending
set     Language {Java zipped}
set      Program src.zip
set       Report 1.html
set      Elapsed 0
set          CPU 0
set       Memory 0
set     Feedback {{Observation of &lt;b&gt;Compile Time Error&lt;/b&gt; &lt;pre&gt;src/T2timeTests.java:1: error: package org.junit does not exist
import static org.junit.Assert.*;
                       ^
src/T2timeTests.java:2: error: package org.junit does not exist
import org.junit.Test;
                ^
src/T2timeTests.java:6: error: cannot find symbol
	@Test
	 ^
  symbol:   class Test
  location: class T2timeTests
src/T2timeTests.java:14: error: cannot find symbol
	@Test (expected = IllegalArgumentException.class) 
	 ^
  symbol:   class Test
  location: class T2timeTests
src/T2timeTests.java:20: error: cannot find symbol
	@Test (expected = IllegalArgumentException.class) 
	 ^
  symbol:   class Test
  location: class T2timeTests
src/T2timeTests.java:26: error: cannot find symbol
	@Test
	 ^
  symbol:   class Test
  location: class T2timeTests
src/T2timeTests.java:35: error: cannot find symbol
	@Test
	 ^
  symbol:   class Test
  location: class T2timeTests
src/T2timeTests.java:9: error: cannot find symbol
		assertEquals(0, new T2time( 0).asSeconds()); 
		^
  symbol:   method assertEquals(int,int)
  location: class T2timeTests
src/T2timeTests.java:10: error: cannot find symbol
		assertEquals(3661, new T2time( 3661).asSeconds());
		^
  symbol:   method assertEquals(int,int)
  location: class T2timeTests
src/T2timeTests.java:11: error: cannot find symbol
		assertEquals(48435, new T2time(48435).asSeconds()); 
		^
  symbol:   method assertEquals(int,int)
  location: class T2timeTests
src/T2timeTests.java:29: error: cannot find symbol
		assertEquals("00:00:00", new T2time( 0).toString()); 
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
src/T2timeTests.java:30: error: cannot find symbol
		assertEquals("00:00:01", new T2time( 1).toString()); 
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
src/T2timeTests.java:31: error: cannot find symbol
		assertEquals("01:01:01", new T2time(3661).toString()); 
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
src/T2timeTests.java:32: error: cannot find symbol
		assertEquals("13:27:15", new T2time(T2time.T2DAYSECONDS-1).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
src/T2timeTests.java:38: error: cannot find symbol
		assertEquals("00:00:00", (new T2time(0,0,0).add(new T2time(0,0,0))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
src/T2timeTests.java:39: error: cannot find symbol
		assertEquals("00:00:01", (new T2time(0,0,1).add(new T2time(0,0,0))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
src/T2timeTests.java:40: error: cannot find symbol
		assertEquals("00:00:00", (new T2time(13,27,15).add(new T2time(0,0,1))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
src/T2timeTests.java:41: error: cannot find symbol
		assertEquals("00:00:01", (new T2time(13,27,15).add(new T2time(0,0,2))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
src/T2timeTests.java:42: error: cannot find symbol
		assertEquals("01:01:01", (new T2time(13,27,15).add(new T2time(1,1,2))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
19 errors&lt;/pre&gt;}}
