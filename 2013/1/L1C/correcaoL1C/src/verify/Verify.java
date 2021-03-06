package verify;

import static org.junit.Assert.assertEquals;
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

import org.junit.BeforeClass;
import org.junit.Test;

public class Verify {
	private static int questionNumber = 0;
	private static final String RESULT_PATTERN = "../q";
	private static final String EXPECTED_PATTERN = "results/";
	private static final Integer questions = 26;
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
			fail("Arquivo " + file.getName() + " n�o encontrado");
		} finally {
			if (bufferedReader != null)
				bufferedReader.close();
		}
		
		return lines;		
	}

	@Test
	public void testQ1() {
		compare();
	}
	
	@Test
	public void testQ2() {
		compare();
	}

	@Test
	public void testQ3() {
		compare();
	}
	
	@Test
	public void testQ4() {
		compare();
	}

	@Test
	public void testQ5() {
		compare();
	}
	
	@Test
	public void testQ6() {
		compare();
	}

	@Test
	public void testQ7() {
		compare();
	}
	
	@Test
	public void testQ8() {
		compare();
	}
	
	@Test
	public void testQ9() {
		compare();
	}
	
	@Test
	public void testQ10() {
		compare();
	}
	
	@Test	
	public void testQ11() {
		compare();
	}
	
	@Test	
	public void testQ12() {
		compare();
	}

	@Test	
	public void testQ13() {
		compare();
	}

	@Test	
	public void testQ14() {
		compare();
	}
	
	@Test	
	public void testQ15() {
		compare();
	}
	
	@Test	
	public void testQ16() {
		compare();
	}

	@Test	
	public void testQ17() {
		compare();
	}

	@Test	
	public void testQ18() {
		compare();
	}

	@Test	
	public void testQ19() {
		compare();
	}

	@Test	
	public void testQ20() {		
		try {
			boolean equals = false;
			String line;
			Integer[] total = new Integer[20];
			Integer k = 0;
			List<String> lines = getLines(resultFiles.get(++questionNumber - 1));			
			
			for (int i = 0; i < 20; i++, k++) {
				line = lines.get(i);
				total[k] = new Integer(line.split("=")[0].trim());
				Integer soma = 0;		
				String[] splits = line.split("=")[1].split("\\+");
				for (int j = 0; j < splits.length; j++) {
					soma += new Integer(splits[j].trim());
				}
				
				assertEquals("Os n�meros gerados n�o correspondem � soma: " + total[k] + ":" + soma, total[k].intValue(), soma.intValue());			
			}
			
			for (int i = 1; i < total.length; i++) {
				equals = (total[0].intValue() == total[i].intValue());
				if (!equals)
					break;
			}
			
			if (equals)
				fail("todas as somas s�o iguais.");
			
			
		} catch (IOException e) {
			fail("erro na leitura do arquivo");
		}
	}

	@Test	
	public void testQ21() {
		compare();
	}

	@Test	
	public void testQ22() {
		compare();
	}

	@Test	
	public void testQ23() {
		compare();
	}
	
	@Test	
	public void testQ24() {
		compare();
	}
	
	@Test	
	public void testQ25() {
		compare();
	}

	@Test	
	public void testQ26() {
		compare();
	}

	private void compare() {
		compare(++questionNumber);
	}
	
	private void compare(int qn) {
		try {
			List<String> lines = getLines(resultFiles.get(qn - 1));
			List<String> expectedLines = getLines(expectedFiles.get(qn - 1)); 
			
			for (int i = 0; i < expectedLines.size(); i++) {
				try {
					assertEquals("Resultado n�o confere (linha " + (i + 1) + ", quest�o " + qn + ").", expectedLines.get(i), lines.get(i));
				} catch(IndexOutOfBoundsException ex) {
					fail("Arquivo gerado com quantidade inferior de linhas ao esperado. Quest�o " + qn);
				}
			}
		} catch (IOException e) {
			fail("erro na leitura do arquivo");
		}
	}
}