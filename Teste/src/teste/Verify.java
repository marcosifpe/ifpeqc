package teste;

import static org.junit.Assert.*;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

public class Verify {
	private static final String FILE_NAMES = "exercicio1_q";
	private static final Integer questions = 5;
	private static List<String> fileNames;

	@BeforeClass
	public static void setUpBeforeClass() throws Exception {
		fileNames = new ArrayList<String>();

		for (int i = 1; i <= questions; ++i) {
			fileNames.add(FILE_NAMES + i + "/" + "s" + i + ".txt");
			File file = new File("../" + fileNames.get(i - 1));
			System.out.println(fileNames.get(i-1));
			System.out.println(file.exists());
		}
	}

	@AfterClass
	public static void tearDownAfterClass() throws Exception {
	}

	@Before
	public void setUp() throws Exception {
	}

	@After
	public void tearDown() throws Exception {
	}

	@Test
	public void test() {
		fail("Not yet implemented");
	}
}