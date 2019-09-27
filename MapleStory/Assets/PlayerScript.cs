using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerScript : MonoBehaviour
{
    [SerializeField]
    private Animator animator;
    [SerializeField]
    private float Hp = 10;
    [SerializeField]
    private GameObject monster;
   


    // Start is called before the first frame update
    void Start()
    {
        animator = GetComponent<Animator>();
    }

    // Update is called once per frame
    void Update()
    {
        AnimatedAttack();
        attack();

        AnimatedDead();
    }

    public void attack()
    {
        if (Input.GetKey("space"))
        {
            if (monster.transform.position.x <= -11)
            {
                print("attack");
                monster.GetComponent<MonsterScript>().Hp = 0;
            }
        }
    }

    public void AnimatedAttack()
    {
        animator.SetBool("attack", Input.GetKey("space"));
    }

    public void AnimatedDead()
    {
        animator.SetFloat("Hp", Hp);
    }
}
