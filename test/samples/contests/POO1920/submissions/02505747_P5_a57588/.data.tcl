set         Date 1583253687
set         Time 2505747
set      Problem P5
set         Team a57588
set     Classify {Compile Time Error}
set         Mark 0
set         Size 2699
set Observations {}
set    Execution -1
set        State pending
set     Language {Java zipped}
set      Program src.zip
set       Report 1.html
set      Elapsed 0
set          CPU 0
set       Memory 0
set     Feedback {{Observation of &lt;b&gt;Compile Time Error&lt;/b&gt; &lt;pre&gt;src/ClientTests.java:1: error: package org.junit does not exist
import static org.junit.Assert.*;
                       ^
src/ClientTests.java:3: error: package org.junit does not exist
import org.junit.Test;
                ^
src/TimeTests.java:1: error: package org.junit does not exist
import static org.junit.Assert.*;
                       ^
src/TimeTests.java:3: error: package org.junit does not exist
import org.junit.Test;
                ^
src/ClientTests.java:40: error: cannot find symbol
	@Test
	 ^
  symbol:   class Test
  location: class ClientTests
src/TimeTests.java:7: error: cannot find symbol
	@Test
	 ^
  symbol:   class Test
  location: class TimeTests
src/TimeTests.java:14: error: cannot find symbol
	@Test (expected = IllegalArgumentException.class)
	 ^
  symbol:   class Test
  location: class TimeTests
src/TimeTests.java:19: error: cannot find symbol
	@Test (expected = IllegalArgumentException.class)
	 ^
  symbol:   class Test
  location: class TimeTests
src/TimeTests.java:24: error: cannot find symbol
	@Test
	 ^
  symbol:   class Test
  location: class TimeTests
src/TimeTests.java:32: error: cannot find symbol
	@Test
	 ^
  symbol:   class Test
  location: class TimeTests
src/ClientTests.java:48: error: cannot find symbol
			assertEquals(expected, os.toString());
			^
  symbol:   method assertEquals(String,String)
  location: class ClientTests
src/TimeTests.java:9: error: cannot find symbol
		assertEquals(0 , new Time(0).asSeconds());
		^
  symbol:   method assertEquals(int,int)
  location: class TimeTests
src/TimeTests.java:10: error: cannot find symbol
		assertEquals(3661, new Time(3661).asSeconds());
		^
  symbol:   method assertEquals(int,int)
  location: class TimeTests
src/TimeTests.java:11: error: cannot find symbol
		assertEquals(48435, new Time(48435).asSeconds());
		^
  symbol:   method assertEquals(int,int)
  location: class TimeTests
src/TimeTests.java:26: error: cannot find symbol
		assertEquals("00:00:00", new Time(0).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class TimeTests
src/TimeTests.java:27: error: cannot find symbol
		assertEquals("00:00:01", new Time(1).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class TimeTests
src/TimeTests.java:28: error: cannot find symbol
		assertEquals("01:01:01", new Time(3661).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class TimeTests
src/TimeTests.java:29: error: cannot find symbol
		assertEquals("13:27:15", new Time(Time.TIMEDAYSECONDS-1).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class TimeTests
src/TimeTests.java:34: error: cannot find symbol
		assertEquals("00:00:00", (new Time (0,0,0).add(new Time(0,0,0))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class TimeTests
src/TimeTests.java:35: error: cannot find symbol
		assertEquals("00:00:01", (new Time (0,0,1).add(new Time(0,0,0))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class TimeTests
src/TimeTests.java:36: error: cannot find symbol
		assertEquals("00:00:00", (new Time (13,27,15).add(new Time(0,0,1))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class TimeTests
src/TimeTests.java:37: error: cannot find symbol
		assertEquals("00:00:01", (new Time (13,27,15).add(new Time(0,0,2))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class TimeTests
src/TimeTests.java:38: error: cannot find symbol
		assertEquals("01:01:01", (new Time(13,27,15).add(new Time(1,1,2))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class TimeTests
23 errors&lt;/pre&gt;}}
