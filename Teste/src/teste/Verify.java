package teste;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.fail;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

public class Verify {
	private static final String RESULT_PATTERN = "../exercicio1_q";
	private static final String EXPECTED_PATTERN = "results/";
	private static final Integer questions = 5;
	private static List<File> resultFiles = new ArrayList<File>();
	private static List<File> expectedFiles = new ArrayList<File>();

	@BeforeClass
	public static void setUpBeforeClass() throws Exception {
		for (int i = 1; i <= questions; ++i) {
			File file = new File(RESULT_PATTERN + i + "/" + "s" + i + ".txt");
			resultFiles.add(file);
		}
		
		for (int i = 1; i <= questions; ++i) {
			File file = new File(EXPECTED_PATTERN + "s" + i + ".txt");
			expectedFiles.add(file);
		}
	}
	
	public List<String> getLines(File file) throws IOException {
		List<String> lines = new ArrayList<String>();
		
		FileInputStream fileInputStream = null;
		DataInputStream dataInputStream = null;
		InputStreamReader inputStreamReader = null;
		BufferedReader bufferedReader = null;
		try {
			fileInputStream = new FileInputStream(file);
			dataInputStream = new DataInputStream(fileInputStream);
			inputStreamReader = new InputStreamReader(dataInputStream);
			bufferedReader = new BufferedReader(inputStreamReader);		
			String line;
			
			while ((line = bufferedReader.readLine()) != null)   {
				line = line.trim();
				if (line.length() > 0)
					lines.add(line.trim());
			}
			
		} catch (FileNotFoundException e) {			
			fail("Arquivo " + file.getName() + " não encontrado");
		} finally {
			if (bufferedReader != null)
				bufferedReader.close();
		}
		
		return lines;		
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
	public void testQ1() {
		try {
			List<String> lines = getLines(resultFiles.get(0));
			List<String> expectedLines = getLines(expectedFiles.get(0)); 
			
			for (int i = 0; i < expectedLines.size(); i++) {
				try {
					assertEquals(expectedLines.get(0), lines.get(0));
				} catch(IndexOutOfBoundsException ex) {
					fail("Arquivo gerado com quantidade inferior de linhas ao esperado");
				}
			}
		} catch (IOException e) {
			fail("erro na leitura do arquivo");
		}
	}
}