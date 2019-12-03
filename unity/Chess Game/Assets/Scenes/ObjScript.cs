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
    float MoveSpeed = 5f;
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
        bool isAtk = false;
        Vector2 enemy = FindEnemy(ref isAtk);
        time += Time.deltaTime;
        TimeForAtk += Time.deltaTime;
        if (TimeForAtk * AtkSpeed >= 1f && isAtk)
        {            
            Attack();
        }
        if(time >= 1f)
        {
            GainMana();
            GainHp();
            time = 0;
        }
        if(Mana >= 100)
        {

        }
    }

    void Attack()
    {
        print("att");
        int damage;
        int rand = Random.Range(0, 100);
        if (rand < CriticalRate)
        {
            damage = Mathf.RoundToInt(AtkDamage * (CriticalMultiplication / 100));
        }
        else
        {
            damage = Mathf.RoundToInt(AtkDamage);
        }
        TimeForAtk = 0;         
    }

    void move(Vector2 enemy)
    {
        Vector3 dir = new Vector3(enemy.x, transform.position.y, enemy.y);
        transform.Translate(dir.normalized * MoveSpeed * Time.deltaTime);
    }

    Vector2 FindEnemy(ref bool isAtk)
    {
        float dis = 100f;
        Vector2 enemy = Vector2.zero;
        for(int x=0; x<8; x++)
        {
            for(int y=0; y<8; y++)
            {
                if(Manager.GetComponent<CreateBoard>().boards[x, y].GetComponent<BoardScript>().isOnUnit)
                {
                    Vector2 newpos = new Vector2(x, y);
                    print(newpos);
                    float newdis = Vector2.Distance(newpos, pos);
                    if (newdis < dis)
                    {
                        enemy = newpos;
                    }
                }
            }
        }
        if (Vector2.Distance(enemy, pos) < AtkRange + 1)
        {
            isAtk = true;
        }
        else
        {
            isAtk = false;
        }
        return enemy;
    }

    void Spell()
    {

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
            pos.x = other.transform.position.x;
            pos.y = other.transform.position.y;
        }
    }
}
