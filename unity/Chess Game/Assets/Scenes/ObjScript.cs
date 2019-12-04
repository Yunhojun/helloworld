using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ObjScript : MonoBehaviour
{
    int HP = 100;//최대 체력
    float HpRegen = 0;//1초당 체력재생
    float AtkSpeed = 1;//초당 공격횟수
    float AtkDamage = 10;//공격력
    int AtkRange = 1;//사거리
    int CriticalRate = 5;//치명타확률
    int CriticalMultiplication = 200;//치명타 배율
    int Mana = 0;//기본마나
    float ManaRegen = 5;//초당 마나재생
    int Defense = 0;//방어력
    int SpellMultiplication = 100;//주문 배율
    float MoveSpeed = 1f;
    Vector2 pos;
    GameObject Manager = null;
    
    float time = 0;
    float TimeForAtk = 0;

    // Start is called before the first frame update
    private void Awake()
    {
        Manager = GameObject.FindGameObjectWithTag("GameController");
    }

    void Start()
    {

    }

    // Update is called once per frame

    private void FixedUpdate()
    {

    }

    void Update()
    {
        Vector2 target = findEnemy();
        move(target);
        time += Time.deltaTime;
        TimeForAtk += Time.deltaTime;
        if (TimeForAtk * AtkSpeed >= 1f)
        {
            //Attack(target);
        }
        if (time >= 1f)
        {
            GainMana();
            GainHp();
            time = 0;
        }
    }    

    Vector2 findEnemy()//가장 가까이 있는 적을 찾아 그 좌표를 리턴(target)
    {
        float dis = 100f;
        Vector2 targetPos = pos;
        bool isAtk = isAtkFunc(targetPos);
        Vector2[] enemy = Manager.GetComponent<CreateBoard>().getEnemy();
        for(int i=0; i<10; i++)
        {
            float newdis = Vector2.Distance(enemy[i], pos);
            if(newdis < dis)
            {
                dis = newdis;
                targetPos = enemy[i];
            }
        }
        return targetPos;
    }

    void move(Vector2 enemy)//target에 가장 가까운 칸으로 이동
    {
        Vector2 temp = Vector2.zero;
        float tempdis = 100f;
        for (int x = -AtkRange; x<= AtkRange; x++)
        {
            for(int y=-AtkRange; y<=AtkRange; y++)
            {
                BoardScript targetBoard = Manager.GetComponent<CreateBoard>().getBoards(enemy.x - x, enemy.y -y).GetComponent<BoardScript>();
                if(!targetBoard.getisOnEnemy())
                {
                    Vector2 newpos = targetBoard.getpos();
                    float newdis = Vector2.Distance(newpos, pos);
                    if (newdis <= tempdis)
                    {
                        tempdis = newdis;
                        temp = newpos;
                    }
                }
            }
        }
        Vector3 dir = new Vector3(temp.x, transform.position.y, temp.y) - transform.position;
        transform.Translate(dir.normalized * MoveSpeed * Time.deltaTime, Space.Self);
        print(dir.normalized * MoveSpeed * Time.deltaTime);
    }

    void Damaged(float damage)
    {
        print("ATTACK");
    }

    void Attack(Vector2 target)
    {
        GameObject targetObject = Manager.GetComponent<CreateBoard>().getBoards(target.x, target.y);
        if (isOnCenter()&& Vector2.Distance(pos,target) <= (float)AtkRange && targetObject.GetComponent<BoardScript>().getisOnEnemy())
        {
            int damage = Mathf.RoundToInt(AtkDamage);
            if (targetObject.GetComponent<BoardScript>().getUnit().tag == "Enemy")
            {
                targetObject.GetComponent<BoardScript>().getUnit().GetComponent<ObjScript>().Damaged(damage);
                print("III");
            }
            TimeForAtk = 0f;
        }
    }

    bool isOnCenter()
    {
        Vector2 realPos = new Vector2(transform.position.x, transform.position.z);
        if(Vector2.Distance(realPos, pos) <= 0.2)
        {
            transform.position = new Vector3(pos.x, transform.position.y, pos.y);
            return true;
        }
        else
        {
            return false;
        }
    }
        
    bool isAtkFunc(Vector2 target)//사거리 안에 적이 있는지 판단
    {
        int dis = Mathf.RoundToInt(Vector2.Distance(target, pos));
        if (dis <= AtkRange)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    void GainMana()
    {
        Mana += Mathf.RoundToInt(ManaRegen);
    }

    void GainHp()
    {
        HP += Mathf.RoundToInt(HpRegen);
    }

    private void OnTriggerEnter(Collider other)
    {
        if(other.tag == "Plane")
        {
            pos = other.GetComponent<BoardScript>().getpos();
        }
    }
}
