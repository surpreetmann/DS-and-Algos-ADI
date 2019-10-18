import java.util.*;
import myplaylist.*;

public class Main
{
  public static void clearScreen()
  {
    try{
        new ProcessBuilder("cmd","/c","cls").inheritIO().start().waitFor();
      }
    catch(Exception e)
    {
      System.out.println("Problem in clearScreen");
    }
  }
  public static void main(String[] args)
  {
    char ch,ch1;
    Scanner sc =new Scanner(System.in);
    String name;
    Playlist playlist=new Playlist();
    System.out.println("Create new playlist?");
    ch=sc.next().charAt(0);
    if(ch=='Y')
    {
      System.out.println("Enter new playlist's name");
      name=sc.nextLine();
      Playlist playlist1=new Playlist();
      System.out.println("New Playlist Created -" +name);
    }
    else
    while(true)
    {
    //clearScreen();
    System.out.println("Playing existing playlist");
    System.out.println("Hit 'P' to display the playlist");
    System.out.println("Hit 'M' to select a specific mode");
    System.out.println("Hit 'Y' to add new songs");
    System.out.println("Hit 'R' to remove the songs");
    System.out.println("Select song to play. Press 'S'");
    System.out.println("Hit 'Q' to quit");
    ch1=sc.next().charAt(0);
    int id;
    int playid;
    if(ch1=='p'|| ch1=='P')
    {
      //System.out.println("Select the playlist : ");
      //playid=sc.nextInt();
      System.out.println("Playing entire playlist in default manner : ");
      System.out.println(playlist.toString());
      System.out.println();
      System.out.println();
    }
    else if(ch1 =='y' || ch1== 'Y')
    {
      System.out.println("Enter song name(id) : ");
      id=sc.nextInt();
      playlist.addSong(id);
    }
    else if(ch1=='r' || ch1=='R')
    {
      System.out.println("Enter the song you want to delete : ");
      id=sc.nextInt();
      System.out.println("Song removed : " +playlist.remove(id));
      System.out.println();
    }
    else if(ch1=='s'|| ch1=='S')
    {
      System.out.println("Select the song(id) : ");
      id=sc.nextInt();
      playlist.play(id);
      System.out.println();
    }
    else if(ch1=='m' || ch1=='M')
    {
      String mod;
      System.out.println("Select the song(id) : ");
      id=sc.nextInt();
      System.out.println("Select mode: 'A','B','C','D'");
      mod=sc.next();
      System.out.println("Playing mode : " +mod);
      playlist.playMode(mod,id);

    }
    else if(ch1=='q' || ch1=='Q')
    {
      System.out.println("Be back soon:/");
      break;
    }
    System.out.println("-----------------------------------");
  }
  }
}
