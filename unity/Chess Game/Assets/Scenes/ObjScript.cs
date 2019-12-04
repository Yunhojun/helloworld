using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ObjScript : MonoBehaviour
{
    public int HP = 100;//최대 체력
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
    GameObject Manager;
    
    float time = 0;
    float TimeForAtk = 0;

    // Start is called before the first frame update
    void Start()
    {
        Manager = GameObject.FindGameObjectWithTag("GameController");
    }

    // Update is called once per frame
    void Update()
    {
        Vector2 target = findEnemy();
        move(target);
        time += Time.deltaTime;
        TimeForAtk += Time.deltaTime;
        if(TimeForAtk * AtkSpeed >= 1f)
        {
            Attack(target);
        }
        if (time >= 1f)
        {
            GainMana();
            GainHp();
            time = 0;
        }
        if(Mana >= 100)
        {

        }
    }    

    Vector2 findEnemy()//가장 가까이 있는 적을 찾아 그 좌표를 리턴(target)
    {
        float dis = 100f;
        Vector2 targetPos = pos;
        bool isAtk = isAtkFunc(targetPos);
        Vector2[] enemy = Manager.GetComponent<CreateBoard>().enemy;
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
                BoardScript targetBoard = Manager.GetComponent<CreateBoard>().boards[Mathf.RoundToInt(enemy.x) - x, Mathf.RoundToInt(enemy.y) - y].GetComponent<BoardScript>();
                if(!targetBoard.isOnEnemy)
                {
                    Vector2 newpos = new Vector2(targetBoard.x, targetBoard.y);
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
        transform.Translate(dir.normalized * MoveSpeed * Time.deltaTime);
    }

    void Attack(Vector2 target)
    {
        GameObject targetObject = Manager.GetComponent<CreateBoard>().boards[Mathf.RoundToInt(target.x), Mathf.RoundToInt(target.y)];
        if(isOnCenter()&& Mathf.RoundToInt(Vector2.Distance(pos,target)) <= AtkRange)
        {
            if (targetObject.GetComponent<BoardScript>().isOnEnemy)
            {
                if (targetObject.GetComponent<BoardScript>().Unit.tag == "Enemy")
                {
                    //targetObject.GetComponent<BoardScript>().Unit.GetComponents<ObjScript>().
                }
                TimeForAtk = 0;
            }
            else
            {
                return;
            }
        }
        else
        {
            return;
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
            pos.x = other.GetComponent<BoardScript>().x;
            pos.y = other.GetComponent<BoardScript>().y;
        }
    }
}
