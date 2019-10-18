package myplaylist;

public class Playlist<E>
{
  private static class Song<E>
  {
    private E id;
    private Song<E> prev;
    private Song<E> next;

  public Song(E i, Song<E> p, Song<E> n) {
    id =i;
    prev=p;
    next=n;
  }
  public E getSongId() {
     return id;
    }
  public Song<E> getPrev() {
     return prev;
    }
    public Song<E> getNext() {
      return next;
     }
     public void setPrev(Song<E> p) {
       prev = p;
     }
      public void setNext(Song<E> n) {
        next = n;
       }


    }

    enum Mode
    {
      A,B,C,D;
    }


    private Song<E> header;
    private Song<E> trailer;
    private int size = 0;
    public String name;
    private Mode mode;


  public Playlist() {
      header=null;
      trailer=null;
      size=0;
    }
    /*public Playlist(String n)
    {
      name=n;
    }*/
    public int size() {
    return size;
  }

  public boolean isEmpty() {
    return size==0;
   }

   public void play(E id)
   {
     //int i=(int)id;
     int flag=1;
     if(isEmpty())
       System.out.println("Playlist is empty");
     Song<E> node=header;
     while(node!=null)
     {
       if(node.getSongId()==id){
         flag=0;
         break;
       }
      node=node.getNext();
     }

     if(flag==0)
     {
      System.out.println("Playing song : " + node.getSongId());  //return id otherwise will play the song from the songs node
     }
     else
      System.out.println("Song doesn't exist");
   }
   public E first() {
     if(isEmpty())
       return null;
     return header.getSongId();
   }
   public E last() {
     if(isEmpty())
       return null;
     return trailer.getSongId();
   }


   public void addSong(E e) {
     if(size>99)
      System.out.println("This playlist is full. You should create another playlist");
    else
    {
      Song<E> newnode=new Song<>(e,trailer,null);
     if(isEmpty())
       header=newnode;
       else
   {
       trailer.setNext(newnode);

   }
   trailer=newnode;
   size++;
 }
 }
 public E removeFirst() {
   if(isEmpty())
     return null;
   E ele=header.getSongId();
   if(size==1)
   {
     header=header.getNext();  //if header is set to null.
     trailer=null;
   }
   else
   {
     header=header.getNext();
     header.setPrev(null);
   }
   size--;
   return ele;
 }

 public E removeLast() {
   if(isEmpty())
     return null;
   E ele=trailer.getSongId();
   if(size==1)
   {
     trailer=trailer.getPrev();
     header=null;
   }
   else
   {
     trailer=trailer.getPrev();
     trailer.setNext(null);
   }

   size--;
   return ele;
 }
 public E remove(E id) {
   int flag=1;
   if(isEmpty())
     return null;

  Song<E> node=header;

  while(node!=null)
  {
    if(node.getSongId()==id){
      flag=0;
      break;
    }
   node=node.getNext();
  }
  if(flag==0){
   E ele=node.getSongId();
   if(header==node)
   {
     header=header.getNext();
     header.setPrev(null);
     if(size==0)
       trailer=null;
   }
   else if(trailer==node)
   {
     trailer=trailer.getPrev();
     trailer.setNext(null);
     if(size==0)
       header=null;
   }
   node.getPrev().setNext(node.getNext());
   node.getNext().setPrev(node.getPrev());
   size--;
   return ele;}
   else
    System.out.println("Song is not present in playlist");
    return null;
 }

 public String toString()
 {
   StringBuilder sb = new StringBuilder("(");         //
   Song<E> walk = header;
   while (walk != null) {
     sb.append(walk.getSongId());
     if (walk != trailer)
       sb.append(", ");
     walk = walk.getNext();
   }
   sb.append(")");
   return sb.toString();
 }


public String playMode1(E id)
{
  StringBuilder sb = new StringBuilder("[ ");
  Song<E> curr=header;
  while(curr!=null)
  {
    if(curr.getSongId()==id)
      break;
    curr=curr.getNext();
  }
  while(curr!=null)
  {
    sb.append(curr.getSongId());
    if(curr!=trailer)
      sb.append(" - ");
    curr=curr.getNext();
  }
  sb.append(" ]");
  return sb.toString();
}

public String playMode2(E id)
{
  StringBuilder sb = new StringBuilder("");
  Song<E> curr=header;
  while(curr!=null)
  {
    if(curr.getSongId()==id)
      break;
    curr=curr.getNext();
  }
  Song<E> curr1=curr;
  int i=0;
  while(i<10)
  {
    sb.append("[");
  while(curr!=null)
  {
    sb.append(curr.getSongId());
    sb.append(" - ");
    curr=curr.getNext();
  }
  curr=header;
  while(curr!=curr1)
  {
    sb.append(curr.getSongId());
    if(curr!=curr1.getPrev())
      sb.append(" - ");
    curr=curr.getNext();
  }
  sb.append(" ] , ");
  i++;
  }
  return sb.toString();
}

public String playMode3(E id)
{
  StringBuilder sb = new StringBuilder("[ ");
  Song<E> curr=header;
  while(curr!=null)
  {
    if(curr.getSongId()==id)
      break;
    curr=curr.getNext();
  }
  int i=0;
  while(i<9)
  {
    sb.append(curr.getSongId());
      sb.append(" - ");
    i++;
  }
  sb.append(curr.getSongId() +" ]");
  return sb.toString();
}

public String playMode4(E id)
{
  StringBuilder sb = new StringBuilder("[ ");
  Song<E> curr=header;
  while(curr!=null)
  {
    if(curr.getSongId()==id)
      break;
    curr=curr.getNext();
  }
  while(curr!=null)
  {
    sb.append(curr.getSongId());
    if(curr!=header)
      sb.append(" - ");
    curr=curr.getPrev();
  }
  sb.append(" ]");
  return sb.toString();
}

 public void playMode(String m,E id)
    {
        mode=Mode.valueOf(m);
        switch (mode)
        {
        case A:
            System.out.println(playMode1(id));
            break;
        case B:
            System.out.println(playMode2(id));
            break;
        case C:
            System.out.println(playMode3(id));
            break;
        case D:
            System.out.println(playMode4(id));
            break;
        default:
            System.out.println(playMode1(id));
            break;
        }
      }
}
