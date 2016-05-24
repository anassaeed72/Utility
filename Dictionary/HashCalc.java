import java.security.MessageDigest;
import java.io.File;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.util.*;
import java.io.*;

public class HashCalc{	
	private static final List<String> places = Arrays.asList("a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","0","1","2","3","4","5","6","7","8","9");
	private static final List<String> characters = Arrays.asList("a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","0","1","2","3","4","5","6","7","8","9");
	private static File file;
	private static final String FileName = "hash.txt";
	private static  String start = "aaaaa";
	private static MessageDigest md = null;
	private static byte[] dataBytes;// = new byte[1024];
	private static byte[] mdbytes;
	private static String finish ="";
	private static boolean permissionToContinue = true;
	private static String current = "";
	// private static StringBuffer sb;
	private static FileWriter fileWritter;
    private static BufferedWriter bufferWritter;
	private static void initalize(){
		try{
			file = new File(FileName);
			if ( file.exists() == false){
				file.createNewFile();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		String last = tail(file);
		if (!last.equals("")) {
			// start = ""+last.charAt(0) +last.charAt(1) +last.charAt(2) +last.charAt(3) +last.charAt(4) +last.charAt(5);
		} else {
			hash(start);
		}
		try{
			md = MessageDigest.getInstance("MD5");
		} catch (Exception e){
			e.printStackTrace();
			return;
		}
		dataBytes = new byte[1024];
		// sb = new StringBuffer();
		try{
			fileWritter = new FileWriter(file.getName(),true);
			bufferWritter = new BufferedWriter(fileWritter);
		} catch (Exception e ){
			e.printStackTrace();
		}
	}
	public static void main(String[] args) {
		initalize();
		// System.out.println(findFinish("aaaGq",1000));
		print(hash1("ccccc"));
		// tester();
		// runner();		
	}
	private static void tester(){
		int ii = 0;
		int iii = 0;
		int iiii = 0;
		int iiiii =1;
		int iiiiii = 1;
		String one = "";
		String two = "";
		String three = "";
		String four = "";
		String five = "";
		String base = "aaaaa";
		for (int i = places.indexOf(""+start.charAt(0));i < 4 ;i++ ) {
			one  = places.get(i);
			for (;ii < places.size() ;ii++ ) {
				two = places.get(ii);
				for (;iii < places.size() ;iii++ ) {
					three = places.get(iii);
					for (;iiii < places.size() ;iiii++ ) {
						four = places.get(iiii);
						for (;iiiii < places.size() ;iiiii++ ) {
							five = places.get(iiiii);
							String test = ""+one+two+three+four+five;
							if (!findFinish(base,1).equals(test)) {
								System.out.println(base);
								System.out.println(test);
								System.exit(0);								
							}							
							base = test;			
						}
						iiiii = 0;						
					}
					iiii = 0;
					// System.out.print( ""+one+two+three+four+five+places.get(iiiiii)+":- ");
					// System.out.println(hash1( ""+one+two+three+four+five+places.get(iiiiii)));
				}
				iii = 0;
			}
			ii = 0;
		}			
	}
	
	public static void runner(){
		int ii = places.indexOf(""+start.charAt(1));
		int iii = places.indexOf(""+start.charAt(2));
		int iiii = places.indexOf(""+start.charAt(3));
		int iiiii = places.indexOf(""+start.charAt(4));
		int iiiiii = places.indexOf(""+start.charAt(5));
		String one = "";
		String two = "";
		String three = "";
		String four = "";
		String five = "";
		for (int i = places.indexOf(""+start.charAt(0));i < 4 ;i++ ) {
			one  = places.get(i);
			for (;ii < places.size() ;ii++ ) {
				two = places.get(ii);
				for (;iii < places.size() ;iii++ ) {
					three = places.get(iii);
					for (;iiii < places.size() ;iiii++ ) {
						four = places.get(iiii);
						for (;iiiii < places.size() ;iiiii++ ) {
							five = places.get(iiiii);
							for (;iiiiii < places.size() ;iiiiii++ ) {
								hash(one+two+three+four+five+places.get(iiiiii));
							}
							iiiiii = 0;													
						}
						iiiii = 0;						
					}
					iiii = 0;
					System.out.print( ""+one+two+three+four+five+places.get(iiiiii)+":- ");
					System.out.println(hash1( ""+one+two+three+four+five+places.get(iiiiii)));
				}
				iii = 0;
			}
			ii = 0;
		}			
	}
	private static void hash(String input){		
		try{
 			md.update(input.getBytes("iso-8859-1"), 0, 6);
 		} catch (Exception e){
			e.printStackTrace();
			return;
		}
 		 mdbytes= md.digest();
        //convert the byte to hex format method 1
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < mdbytes.length; i++) {
          sb.append(Integer.toString((mdbytes[i] & 0xff) + 0x100, 16).substring(1));
        }
        // try{		
    		// bufferWritter.append("\n"+input +": " +sb.toString());    	
    	// } catch (Exception e ){
    		// e.printStackTrace();
    	// }
	}
	private static String hash1(String input){		
		try{
 			md.update(input.getBytes("iso-8859-1"), 0, 5);
 		} catch (Exception e){
			e.printStackTrace();
			return "";
		}
 		mdbytes= md.digest();
        //convert the byte to hex format method 1
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < mdbytes.length; i++) {
          sb.append(Integer.toString((mdbytes[i] & 0xff) + 0x100, 16).substring(1));
        }
        return sb.toString();
	}	
	public static String tail( File file ) {
   
	    RandomAccessFile fileHandler = null;
	    try {
	        fileHandler = new RandomAccessFile( file, "r" );
	        long fileLength = fileHandler.length() - 1;
	        StringBuilder sb = new StringBuilder();

	        for(long filePointer = fileLength; filePointer != -1; filePointer--){
	            fileHandler.seek( filePointer );
	            int readByte = fileHandler.readByte();

	            if( readByte == 0xA ) {
	                if( filePointer == fileLength ) {
	                    continue;
	                }
	                break;

	            } else if( readByte == 0xD ) {
	                if( filePointer == fileLength - 1 ) {
	                    continue;
	                }
	                break;
	            }

	            sb.append( ( char ) readByte );
	        }

	        String lastLine = sb.reverse().toString();
	        return lastLine;
	    } catch( Exception e ) {
	        e.printStackTrace();
	        return null;
	    }  finally {
	        if (fileHandler != null )
	            try {
	                fileHandler.close();
	            } catch (Exception e) {
	                /* ignore */
	            }
	    }
	}
	private static String findFinish(String start, int number){
		String output = "";
		int quantum = 62;
		int zero = characters.indexOf(""+start.charAt(0));
		int one = characters.indexOf(""+start.charAt(1));
		int two = characters.indexOf(""+start.charAt(2));
		int three = characters.indexOf(""+start.charAt(3));
		int four = characters.indexOf(""+start.charAt(4));
		if (number >= Math.pow(quantum,4)) {
			zero+=(number/(int)Math.pow(quantum,4));
			number= (number-(number/(int)Math.pow(quantum,4))*(int)Math.pow(quantum,4));
		}
		if (number >= Math.pow(quantum,3)) {
			one+=(number/(int)Math.pow(quantum,3));
			number=(number-(number/(int)Math.pow(quantum,3))*(int)Math.pow(quantum,3));
		}
		if (number >= Math.pow(quantum,2)) {
			two+=(number/(int)Math.pow(quantum,2));
			number=(number-(number/(int)Math.pow(quantum,2))*(int)Math.pow(quantum,2));
		}
		if (number >= quantum) {
			three+=(number/quantum);
			number=(number-(number/quantum)*quantum);
		}
		if (number > 0) {
			four+=(number);
		}
		if (four == 62) {
			four = 0;
			three= three+1;
		}
		if (three == 62) {
			three = 0;
			two =two+1;
		}
		if (two == 62) {
			two = 0;
			one+=1;
		}
		if (one == 62) {
			one = 0;
			zero +=1;
		}
		if (zero == 62) {
			zero = 0;
		}
		output = "" + characters.get(zero);
		output+= characters.get(one); 
		output+=characters.get(two);
		output+= characters.get(three);
		output+= characters.get(four);
		return output;
	}
	private static void print(String input){

		System.out.println(input);
	}
	private static void print( int input){
		
		System.out.println(""+ input);
	}

}
