set         Date 1582899104
set         Time 2151164
set      Problem P6
set         Team a64538
set     Classify {Compile Time Error}
set         Mark 0
set         Size 1638
set Observations {}
set    Execution -1
set        State pending
set     Language {Java zipped}
set      Program src.zip
set       Report 1.html
set      Elapsed 0
set          CPU 0
set       Memory 0
set     Feedback {{Observation of &lt;b&gt;Compile Time Error&lt;/b&gt; &lt;pre&gt;src/PiratesTests.java:1: error: package org.junit does not exist
import static org.junit.Assert.*;
                       ^
src/PiratesTests.java:2: error: package org.junit does not exist
import org.junit.Test;
                ^
src/PiratesTests.java:5: error: cannot find symbol
	@Test
	 ^
  symbol:   class Test
  location: class PiratesTests
src/PiratesTests.java:11: error: cannot find symbol
	@Test (expected = IllegalArgumentException.class)
	 ^
  symbol:   class Test
  location: class PiratesTests
src/PiratesTests.java:16: error: cannot find symbol
	@Test (expected = IllegalArgumentException.class)
	 ^
  symbol:   class Test
  location: class PiratesTests
src/PiratesTests.java:21: error: cannot find symbol
	@Test (expected = IllegalArgumentException.class)
	 ^
  symbol:   class Test
  location: class PiratesTests
src/PiratesTests.java:26: error: cannot find symbol
	@Test (expected = IllegalArgumentException.class)
	 ^
  symbol:   class Test
  location: class PiratesTests
src/PiratesTests.java:49: error: cannot find symbol
	@Test
	 ^
  symbol:   class Test
  location: class PiratesTests
src/PiratesTests.java:57: error: cannot find symbol
	@Test
	 ^
  symbol:   class Test
  location: class PiratesTests
src/PiratesTests.java:7: error: cannot find symbol
		assertEquals(3151,     new Pirates(3151).getF());
		^
  symbol:   method assertEquals(int,int)
  location: class PiratesTests
src/PiratesTests.java:8: error: cannot find symbol
		assertEquals(14115123, new Pirates(14115123).getF());
		^
  symbol:   method assertEquals(int,int)
  location: class PiratesTests
src/PiratesTests.java:51: error: cannot find symbol
		assertEquals(false,     new Pirates(3151).isOnlyEnemies(1));
		^
  symbol:   method assertEquals(boolean,boolean)
  location: class PiratesTests
src/PiratesTests.java:52: error: cannot find symbol
		assertEquals(true,     new Pirates(3151).isOnlyEnemies(3));
		^
  symbol:   method assertEquals(boolean,boolean)
  location: class PiratesTests
src/PiratesTests.java:53: error: cannot find symbol
		assertEquals(false, new Pirates(14115123).isOnlyEnemies(3));
		^
  symbol:   method assertEquals(boolean,boolean)
  location: class PiratesTests
src/PiratesTests.java:54: error: cannot find symbol
		assertEquals(true, new Pirates(14115123).isOnlyEnemies(12));
		^
  symbol:   method assertEquals(boolean,boolean)
  location: class PiratesTests
src/PiratesTests.java:59: error: cannot find symbol
		assertEquals(3,     new Pirates(3151).smallestStep(1));
		^
  symbol:   method assertEquals(int,int)
  location: class PiratesTests
src/PiratesTests.java:60: error: cannot find symbol
		assertEquals(12, new Pirates(14115123).smallestStep(1));
		^
  symbol:   method assertEquals(int,int)
  location: class PiratesTests
17 errors&lt;/pre&gt;}}
