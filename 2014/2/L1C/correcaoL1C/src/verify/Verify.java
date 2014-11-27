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
import java.util.StringTokenizer;

import org.junit.BeforeClass;
import org.junit.FixMethodOrder;
import org.junit.Test;
import org.junit.runners.MethodSorters;

@FixMethodOrder(MethodSorters.NAME_ASCENDING)
public class Verify {
	private static int questionNumber = 0;
	private static final String RESULT_PATTERN = "../q";
	private static final String EXPECTED_PATTERN = "results/";
	private static final Integer questions = 29;
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

			while ((line = bufferedReader.readLine()) != null) {
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

	@Test
	public void testQ01() {
		compare();
	}

	@Test
	public void testQ02() {
		compare();
	}

	@Test
	public void testQ03() {
		compare();
	}

	@Test
	public void testQ04() {
		compare();
	}

	@Test
	public void testQ05() {
		compare();
	}

	@Test
	public void testQ06() {
		compare();
	}

	@Test
	public void testQ07() {
		compare();
	}

	@Test
	public void testQ08() {
		compare();
	}

	@Test
	public void testQ09() {
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
		compare();
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

	@Test
	public void testQ27() {
		compare();
	}

	@Test
	public void testQ28() {
		compare();
	}

	@Test
	public void testQ29() {
		compare();
	}

	private void compare() {
		compare(++questionNumber);
	}

	private void compare(int qn) {
		try {
			List<String> lines = getLines(resultFiles.get(qn - 1));

			if (qn != 22) {
				List<String> expectedLines = getLines(expectedFiles.get(qn - 1));

				for (int i = 0; i < expectedLines.size(); i++) {
					try {
						assertEquals("Resultado não confere (linha " + (i + 1)
								+ ", questão " + qn + ").",
								expectedLines.get(i), lines.get(i));
					} catch (IndexOutOfBoundsException ex) {
						fail("Arquivo gerado com quantidade inferior de linhas ao esperado. Questão "
								+ qn);
					}
				}
			} else {
				Integer MAX = 1000, i, min, next;

				for (i = 0, min = 1; i < lines.size(); i++) {
					StringTokenizer st = new StringTokenizer(lines.get(i));
					assertEquals("Não gerou 23 números randômicos por linha.", new Integer(st.countTokens()), new Integer(23));
					while (st.hasMoreTokens()) {
						next = new Integer(st.nextToken());
						if (next < min) {
							assertEquals("Não ordenou corretamente os números gerados", true, false);
						}
						
						if (next > MAX || next < 1) {
							assertEquals("Não gerou os números no intervalo correto", true, false);
						}
					}
					
					min = 1;
				}

			}
		} catch (IOException e) {
			fail("erro na leitura do arquivo");
		}
	}
}