interface I{
    int f(int i);
}

public class demo {
    private int a;
    demo(int i)
    {
        a = i;
    }
    int f(I i, int j)
    {
        return i.f(a + j);
    }

    public static void main(String[] args) {
        demo m = new demo(2);
        m.a += 3;
        System.out.println(m.f(i -> i + i, 12));
    }

}
// 有点抽象...