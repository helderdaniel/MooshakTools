set         Date 1583152266
set         Time 2404326
set      Problem P4
set         Team a62287
set     Classify {Compile Time Error}
set         Mark 0
set         Size 3034
set Observations {}
set    Execution -1
set        State pending
set     Language {Java zipped}
set      Program A.zip
set       Report 1.html
set      Elapsed 0
set          CPU 0
set       Memory 0
set     Feedback {{Observation of &lt;b&gt;Compile Time Error&lt;/b&gt; &lt;pre&gt;A/ClientTests.java:3: error: package org.junit does not exist
import static org.junit.Assert.*;
                       ^
A/ClientTests.java:4: error: package org.junit does not exist
import org.junit.Test;
                ^
A/T2timeTests.java:5: error: package org.junit does not exist
import static org.junit.Assert.*;
                       ^
A/T2timeTests.java:7: error: package org.junit does not exist
import org.junit.Test;
                ^
A/ClientTests.java:48: error: cannot find symbol
			assertEquals(expected, os.toString());
			^
  symbol:   method assertEquals(String,String)
  location: class ClientTests
A/ClientTests.java:59: error: cannot find symbol
			assertEquals(expected, os.toString());
			^
  symbol:   method assertEquals(String,String)
  location: class ClientTests
A/T2timeTests.java:13: error: cannot find symbol
		assertEquals(0, new T2time(0).asSeconds());
		^
  symbol:   method assertEquals(int,int)
  location: class T2timeTests
A/T2timeTests.java:14: error: cannot find symbol
		assertEquals(3661, new T2time(3661).asSeconds());
		^
  symbol:   method assertEquals(int,int)
  location: class T2timeTests
A/T2timeTests.java:16: error: cannot find symbol
		assertEquals(48435, new T2time(48435).asSeconds());
		^
  symbol:   method assertEquals(int,int)
  location: class T2timeTests
A/T2timeTests.java:32: error: cannot find symbol
		assertEquals("00:00:00", new T2time( 0).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
A/T2timeTests.java:33: error: cannot find symbol
		assertEquals("00:00:01", new T2time( 1).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
A/T2timeTests.java:34: error: cannot find symbol
		assertEquals("01:01:01", new T2time(3661).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
A/T2timeTests.java:35: error: cannot find symbol
		assertEquals("13:27:15", new T2time(T2time.T2DAYSECONDS-1).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
A/T2timeTests.java:40: error: cannot find symbol
		assertEquals("00:00:00", (new T2time(0,0,0).add(new T2time(0,0,0))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
A/T2timeTests.java:41: error: cannot find symbol
		assertEquals("00:00:01", (new T2time(0,0,1).add(new T2time(0,0,0))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
A/T2timeTests.java:42: error: cannot find symbol
		assertEquals("00:00:00", (new T2time(13,27,15).add(new T2time(0,0,1))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
A/T2timeTests.java:43: error: cannot find symbol
		assertEquals("00:00:01", (new T2time(13,27,15).add(new T2time(0,0,2))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
A/T2timeTests.java:44: error: cannot find symbol
		assertEquals("01:01:01", (new T2time(13,27,15).add(new T2time(1,1,2))).toString());
		^
  symbol:   method assertEquals(String,String)
  location: class T2timeTests
18 errors&lt;/pre&gt;}}
