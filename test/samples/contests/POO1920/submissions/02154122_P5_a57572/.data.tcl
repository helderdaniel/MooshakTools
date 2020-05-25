set         Date 1582902062
set         Time 2154122
set      Problem P5
set         Team a57572
set     Classify {Compile Time Error}
set         Mark 0
set         Size 2167
set Observations {}
set    Execution -1
set        State pending
set     Language {Java zipped}
set      Program src.zip
set       Report 1.html
set      Elapsed 0
set          CPU 0
set       Memory 0
set     Feedback {{Observações de &lt;b&gt;Compile Time Error&lt;/b&gt; &lt;pre&gt;src/ClientTest.java:3: error: class Client is public, should be declared in a file named Client.java
public class Client {
       ^
src/junit.java:1: error: package org.junit does not exist
import static org.junit.Assert.*;
                       ^
src/junit.java:2: error: package org.junit does not exist
import org.junit.Test;
                ^
src/junit.java:12: error: cannot find symbol
	@Test (expected = IllegalArgumentException.class)
	 ^
  symbol:   class Test
  location: class T2T2timeTests
src/junit.java:16: error: cannot find symbol
	@Test (expected = IllegalArgumentException.class)
	 ^
  symbol:   class Test
  location: class T2T2timeTests
src/junit.java:21: error: cannot find symbol
	@Test
	 ^
  symbol:   class Test
  location: class T2T2timeTests
src/junit.java:29: error: cannot find symbol
	@Test
	 ^
  symbol:   class Test
  location: class T2T2timeTests
src/junit.java:8: error: cannot find symbol
		assertEquals(0, new T2time( 0).asSeconds());
		^
  symbol:   method assertEquals(int,int)
  location: class T2T2timeTests
src/junit.java:9: error: cannot find symbol
		assertEquals(3661, new T2time( 3661).asSeconds());
		^
  symbol:   method assertEquals(int,int)
  location: class T2T2timeTests
src/junit.java:10: error: cannot find symbol
		assertEquals(48435, new T2time(48435).asSeconds()); }
		^
  symbol:   method assertEquals(int,int)
  location: class T2T2timeTests
src/junit.java:23: error: cannot find symbol
	assertEquals("00:00:00", new T2time( 0).toString());
	^
  symbol:   method assertEquals(String,String)
  location: class T2T2timeTests
src/junit.java:24: error: cannot find symbol
	assertEquals("00:00:01", new T2time( 1).toString());
	^
  symbol:   method assertEquals(String,String)
  location: class T2T2timeTests
src/junit.java:25: error: cannot find symbol
	assertEquals("01:01:01", new T2time(3661).toString());
	^
  symbol:   method assertEquals(String,String)
  location: class T2T2timeTests
src/junit.java:26: error: cannot find symbol
	assertEquals("13:27:15", new T2time(T2time.T2DAYSECONDS-1).toString());
	^
  symbol:   method assertEquals(String,String)
  location: class T2T2timeTests
src/junit.java:31: error: cannot find symbol
	assertEquals("00:00:00",
	^
  symbol:   method assertEquals(String,String)
  location: class T2T2timeTests
src/junit.java:33: error: cannot find symbol
	assertEquals("00:00:01",
	^
  symbol:   method assertEquals(String,String)
  location: class T2T2timeTests
src/junit.java:35: error: cannot find symbol
	assertEquals("00:00:00",
	^
  symbol:   method assertEquals(String,String)
  location: class T2T2timeTests
src/junit.java:37: error: cannot find symbol
	assertEquals("00:00:01",
	^
  symbol:   method assertEquals(String,String)
  location: class T2T2timeTests
src/junit.java:39: error: cannot find symbol
	assertEquals("01:01:01",
	^
  symbol:   method assertEquals(String,String)
  location: class T2T2timeTests
19 errors&lt;/pre&gt;}}
