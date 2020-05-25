set         Date 1583232937
set         Time 2484997
set      Problem P5
set         Team a54436
set     Classify {Compile Time Error}
set         Mark 0
set         Size 1399
set Observations {}
set    Execution -1
set        State pending
set     Language {Java zipped}
set      Program src.zip
set       Report 1.html
set      Elapsed 0
set          CPU 0
set       Memory 0
set     Feedback {{Observações de &lt;b&gt;Compile Time Error&lt;/b&gt; &lt;pre&gt;src/T2timeTests.java:1: error: package org.junit does not exist
import static org.junit.Assert.*;
                       ^
src/T2timeTests.java:3: error: package org.junit does not exist
import org.junit.Test;
                ^
src/T2timeTests.java:7: error: cannot find symbol
	@Test
	 ^
  symbol:   class Test
  location: class T2timeTests
src/T2timeTests.java:14: error: cannot find symbol
	@Test (expected = IllegalArgumentException.class)
	 ^
  symbol:   class Test
  location: class T2timeTests
src/T2timeTests.java:19: error: cannot find symbol
	@Test (expected = IllegalArgumentException.class)
	 ^
  symbol:   class Test
  location: class T2timeTests
src/T2timeTests.java:24: error: cannot find symbol
	@Test
	 ^
  symbol:   class Test
  location: class T2timeTests
src/T2timeTests.java:32: error: cannot find symbol
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
src/T2timeTests.java:26: error: cannot find symbol
	assertEquals("00:00:00", new T2time( 0).toString());
	^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
src/T2timeTests.java:27: error: cannot find symbol
	assertEquals("00:00:01", new T2time( 1).toString());
	^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
src/T2timeTests.java:28: error: cannot find symbol
	assertEquals("01:01:01", new T2time(3661).toString());
	^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
src/T2timeTests.java:29: error: cannot find symbol
	assertEquals("13:27:15", new T2time(T2time.T2DAYSECONDS-1).toString());
	^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
src/T2timeTests.java:34: error: cannot find symbol
		assertEquals("00:00:00",
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
src/T2timeTests.java:36: error: cannot find symbol
		assertEquals("00:00:01",
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
src/T2timeTests.java:38: error: cannot find symbol
		assertEquals("00:00:00",
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
src/T2timeTests.java:40: error: cannot find symbol
		assertEquals("00:00:01",
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
src/T2timeTests.java:42: error: cannot find symbol
		assertEquals("01:01:01",
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
19 errors&lt;/pre&gt;}}
