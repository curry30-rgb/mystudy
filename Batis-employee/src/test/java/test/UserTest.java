package test;

import com.itheima.pojo.User;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.junit.Test;

import java.io.IOException;
import java.io.InputStream;
import java.util.List;

public class UserTest {
    @Test
    public void getAllTest() throws IOException {
        //查找全部
        InputStream in = Resources.getResourceAsStream("mybatis-config.xml");
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(in);
        SqlSession sqlSession = sqlSessionFactory.openSession();

        List<User> users = sqlSession.selectList("com.itheima.pojo.User.getAll");
        for(User user:users){
            System.out.println(user);
        }
    }

    @Test
    public void findByIdTest() throws IOException {
        //读取核心配置文件
        //通过id查找一个
        InputStream in = Resources.getResourceAsStream("mybatis-config.xml");//核心配置文件  原料
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(in);//造工厂
        SqlSession sqlSession = sqlSessionFactory.openSession();

        User user=sqlSession.selectOne("com.itheima.pojo.User.findById",1);
        System.out.println(user);
    }

    @Test
    public void addUserTest() throws IOException {
        //添加用户
        InputStream in = Resources.getResourceAsStream("mybatis-config.xml");
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(in);
        SqlSession sqlSession = sqlSessionFactory.openSession();

        User user= new User();
        user.setName("张铭珊");
        user.setAge(18);
        user.setPosition("工程师");

        int rowNum = sqlSession.insert("com.itheima.pojo.User.addUser",user);
        sqlSession.commit();//必须把实务手动停止
        System.out.println("处理了"+rowNum+"行。添加成功！");
    }

    @Test
    public void updateByIdTest() throws IOException {
        //更新
        InputStream in = Resources.getResourceAsStream("mybatis-config.xml");
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(in);
        SqlSession sqlSession = sqlSessionFactory.openSession();

        User user = new User();
        user.setAge(20);
        user.setPosition("画家");
        user.setId(5);

        int rowNum = sqlSession.update("com.itheima.pojo.User.updateById", user);
        sqlSession.commit();
        System.out.println("处理了"+rowNum+"行。修改成功！");
    }

    @Test
    public void delectByIdTest() throws IOException {
        //通过id删除
        InputStream in = Resources.getResourceAsStream("mybatis-config.xml");
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(in);
        SqlSession sqlSession = sqlSessionFactory.openSession();

        int deleterow = sqlSession.delete("com.itheima.pojo.User.delectById", 5);
        sqlSession.commit();//必须把实务手动停止
        System.out.println("处理了"+deleterow+"行。删除成功！");
    }
}
