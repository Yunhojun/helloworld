using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Status : MonoBehaviour
{
    [SerializeField]
    private float cycle = 0;
    private int InstancePattern = 1;
    [SerializeField]
    private GameObject monster;
    [SerializeField]
    private int count = 0;

    public GameObject[] arr = new GameObject[20];

    // Start is called before the first frame update
    void Start()
    {
        for(int i = 0; i < 20; i++)
        {
            arr[i] = Instantiate<GameObject>(monster);
        }
    }

    // Update is called once per frame
    void Update()
    {
        cycle += Time.deltaTime;
        RandomCycle();
    }

    public void RandomCycle()
    {
        if (cycle >= 2.0f)
        {
            MoveMonster();
            cycle = 0;
        }
    }

    public void MoveMonster()
    {
        if(count >= 20)
        {
            count = 0;
        }
        arr[count].GetComponent<MonsterScript>().Velocity = 1;
        count++;
    }
}
