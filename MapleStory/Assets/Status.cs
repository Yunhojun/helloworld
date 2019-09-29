using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Status : MonoBehaviour
{
    [SerializeField]
    private float cycle = 0;
    [SerializeField]
    private GameObject monster;
    private int pattern = 0;

    // Start is called before the first frame update
    void Start()
    {
        pattern = Random.Range(0, 3);
    }

    // Update is called once per frame
    void Update()
    {
        cycle += Time.deltaTime;
        RandomCycle();
    }

    public void RandomCycle()
    {

        if (pattern == 0)
        {
            if(cycle >= 1f){
                cycle = 0;
                CreateMonster();
                print(pattern);
            }
        }
        
        else if (pattern == 1)
        {
            if (cycle >= 1.5f)
            {
                cycle = 0;
                CreateMonster();
                print(pattern);
            }
        }

        else if (pattern == 2)
        {
            if(cycle >= 4f)
            {
                cycle = 0;
                CreateMonster();
                print(pattern);
            }
        }
        
    }

    public void CreateMonster()
    {
        Instantiate<GameObject>(monster);
        pattern = Random.Range(0, 3);
    }
}
